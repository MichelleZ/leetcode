// Source: https://leetcode.com/problems/combination-sum/
// Author: Miao Zhang
// Date:   2021-01-08

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(candidates, target, 0, tmp, res);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, int start, vector<int>& tmp, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        int i;
        for (i = start; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                return;
            }
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, tmp, res);
            tmp.pop_back();
        }
    }
};
