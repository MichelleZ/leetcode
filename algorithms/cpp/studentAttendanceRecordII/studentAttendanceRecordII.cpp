// Source: https://leetcode.com/problems/student-attendance-record-ii/
// Author: Miao Zhang
// Date:   2021-02-21

/*********************************************************
 * dp[i] total number of rewardable combination of 'L' and 'P' with length i
 * 1 without A
 *   1) ends with 'P'
 *      dp[i] = dp[i - 1]
 *   2) ends with 'L'
 *      PLLL
 *      dp[i] = dp[i - 1] - dp[i - 4]
 * 2 with A
 *   1...i-1.A.i+1...n
 *    i-1    A  n-i
 *    dp[i-1] * dp[n-i]
*********************************************************/
class Solution {
public:
    int checkRecord(int n) {
        vector<long long> dp(n <= 3 ? 4 : n + 1);
        dp[0] = 1;
        dp[1] = 2; // P or L
        dp[2] = 4;
        dp[3] = 7; // LLL

        for (int i = 4; i <= n; i++) {
            // dp[i] = dp[i - 1] + dp[i - 1] - dp[i - 4]
            dp[i] = (2 * dp[i - 1]) % M + (M - dp[i - 4]) % M;
        }

        long long sums = dp[n];
        for (int i = 1; i <= n; i++) {
            sums += (dp[i - 1] * dp[n - i]) % M;
        }
        return (int)(sums % M);
    }

private:
    long long M = 1000000007;
};
