// Source: https://leetcode.com/problems/combinations/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> nums(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i + 1;
        }
        vector<int> path;
        dfs(nums, k, 0, res, path);
        return res;
    }
    
    void dfs (vector<int>& nums, int k, int start,
              vector<vector<int>>& res, vector<int>& path) {
        if (start > nums.size()) return;
        if (k == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, k - 1, i + 1, res, path);
            path.pop_back();
        }
    }
};
