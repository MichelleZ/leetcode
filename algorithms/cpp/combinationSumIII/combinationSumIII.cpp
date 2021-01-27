// Source: https://leetcode.com/problems/combination-sum-iii/
// Author: Miao Zhang
// Date:   2021-01-27

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> nums(9, 0);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i + 1;
        }
        dfs(nums, k, n, 0, {}, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int k, int n, int start, 
             vector<int> path, vector<vector<int>>& res) {
        if (k < 0 or n < 0) {
            return;
        }
        if (k == 0 && n == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, k - 1, n - nums[i], i + 1, path, res);
            path.pop_back();
        }
    }
};
