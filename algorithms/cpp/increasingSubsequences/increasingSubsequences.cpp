// Source: https://leetcode.com/problems/increasing-subsequences/
// Author: Miao Zhang
// Date:   2021-02-16

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, res, path);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void dfs(vector<int>& nums, int pos, set<vector<int>>& res, vector<int>& path) {
        if (path.size() >= 2) {
            res.insert(path);
        }
        for (int i = pos; i < nums.size(); i++) {
            if (path.empty() || nums[i] >= path.back()) {
                path.push_back(nums[i]);
                dfs(nums, i + 1, res, path);
                path.pop_back();
            }
        }
    }
};
