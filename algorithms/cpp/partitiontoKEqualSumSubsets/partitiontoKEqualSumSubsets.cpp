// Source: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sums = accumulate(nums.begin(), nums.end(), 0);
        if (sums % k != 0) return false;
        int target = sums / k;
        
        sort(nums.begin(), nums.end());
        int row = nums.size() - 1;
        if (nums[row] > target) return false;
        while (row >= 0 && nums[row] == target) {
            row--;
            k--;
        }
        
        vector<int> groups(k, 0);
        return dfs(groups, nums, row, target);
    }
    
private:
    bool dfs(vector<int>& groups, vector<int>& nums, int row, int target) {
        if (row < 0) return true;
        int v = nums[row--];
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] + v <= target) {
                groups[i] += v;
                if (dfs(groups, nums, row, target)) return true;
                groups[i] -= v;
            }
            if (groups[i] == 0) break;
        }
        return false;
    }
};
