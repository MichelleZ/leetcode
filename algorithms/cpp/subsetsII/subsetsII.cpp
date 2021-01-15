// Source: https://leetcode.com/problems/subsets-ii/
// Author: Miao Zhang
// Date:   2021-01-15

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        res.push_back(path);
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, res, path);
        return res;
    }
    
    void dfs(vector<int>& nums, int start, 
             vector<vector<int>>& res, vector<int>& path) {
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            res.push_back(path);
            dfs(nums, i + 1, res, path);
            path.pop_back();
        }
    }
};
