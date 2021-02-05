// Source: https://leetcode.com/problems/combination-sum-iv/
// Author: Miao Zhang
// Date:   2021-02-05

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        memo[0] = 1;
        return dfs(nums, target, memo);
    }
    
    int dfs(vector<int>& nums, int target, vector<int>& memo) {
        if (target < 0) return 0;
        if (memo[target] != -1) return memo[target];
        int res = 0;
        for (auto& n: nums) {
            res += dfs(nums, target - n, memo);
        }
        memo[target] = res;
        return memo[target];
    }
};
