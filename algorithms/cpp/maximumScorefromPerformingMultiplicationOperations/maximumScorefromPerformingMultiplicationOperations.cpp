// Source: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<int>> cache(m, vector<int>(m, INT_MIN));
        function<int(int, int)> dp = [&] (int i, int j) {
            int k = n - (j - i + 1);
            if (k == m) return 0;
            int& res = cache[i][k];
            if (res != INT_MIN) return res;
            return res = max(dp(i + 1, j) + nums[i] * multipliers[k],
                             dp(i, j - 1) + nums[j] * multipliers[k]);
        };
        return dp(0, n - 1);
    }
};
