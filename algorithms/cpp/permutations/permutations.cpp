// Source: https://leetcode.com/problems/permutations/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteDfs(nums, 0, res);
        return res;
    }
    
    void permuteDfs(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            permuteDfs(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};
