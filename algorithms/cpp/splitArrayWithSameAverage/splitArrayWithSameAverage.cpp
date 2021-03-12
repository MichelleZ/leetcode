// Source: https://leetcode.com/problems/split-array-with-same-average/
// Author: Miao Zhang
// Date:   2021-03-12

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sums = std::accumulate(nums.begin(), nums.end(), 0);
        std::sort(nums.begin(), nums.end());
        // sums / n = subsums / len
        // sums * len = subsums * n
        // sums * len / n = subsums
        for (int len = 1; len <= n / 2; len++) {
            if (sums * len % n == 0 && dfs(nums, 0, len, sums * len / n)) {
                return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<int>& nums, int start, int len, int target) {
        if (len == 0) return target == 0;
        for (int i = start; i < nums.size() - len + 1; i++) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            if (dfs(nums, i + 1, len - 1, target - nums[i])) return true;
        }
        return false;
    }
};
