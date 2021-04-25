// Source: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Author: Miao Zhang
// Date:   2021-04-25

/*********************************************************
 * dp[i][k]: 1-i jobs in k days
 * dp[i][k] = min(dp[j][k - 1]) + max(jobs[j + 1 --- i]) k - 1 <= j < i
 * dp[0][0] = 0
 * dp[n][d]
*********************************************************/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n) return -1;
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= d; k++) {
                int tmp = 0;
                for (int j = i - 1; j >= k - 1; j--) {
                    tmp = max(tmp, jobDifficulty[j]);
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + tmp);
                }
            }
        }
        return dp[n][d];
    }
};
