// Source: https://leetcode.com/problems/count-numbers-with-unique-digits/
// Author: Miao Zhang
// Date:   2021-02-04

/******************************************************
 *f[0] = 0 (1)
 *f[1] = 10 (0-9)
 *f[2] = 9 * 9 (1-9 | 0-9)
 *f[3] = 9 * 9 * 8 (1-9 | 0-9 | 0-9)
 *f[4] = 9 * 9 * 8 * 7 (1-9 | 0-9 | 0-9 | 0-9)
 *f[i] = f[i - 1] * (10 - i + 1)
******************************************************/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> dp(9, 0);
        dp[1] = 10;
        dp[2] = 9 * 9;
        for (int i = 3; i < min(9, n + 1); i++) {
            dp[i] = dp[i - 1] * (10 - i + 1);
        }
        int res = 0;
        for (int i = 0; i < min(9, n + 1); i++) {
            res += dp[i];
        }
        return res;
    }
};
