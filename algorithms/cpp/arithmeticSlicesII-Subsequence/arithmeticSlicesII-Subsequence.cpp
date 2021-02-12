// Source: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Author: Miao Zhang
// Date:   2021-02-12

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int n = A.size();
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long delta = (long long)A[i] - A[j];
                dp[i][delta]++;
                if (dp[j].count(delta)) {
                    dp[i][delta] += dp[j][delta];
                    res += dp[j][delta];
                }
            }
        }
        return res;
    }
};
