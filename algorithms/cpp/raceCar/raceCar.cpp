// Source: https://leetcode.com/problems/race-car/
// Author: Miao Zhang
// Date:   2021-03-14

class Solution {
public:
    int racecar(int target) {
        // dp[i]: the minimum number required to reach position i
        vector<int> dp(target + 1, INT_MAX);
        for (int i = 1; i <= target; i++) {
            // --------->j
            //    k<------
            //     --------->i
            int j = 1, cnt1 = 1;
            for (; j < i; j = (1 << ++cnt1) - 1) {
                for (int k = 0, cnt2 = 0; k < j; k = (1 << ++cnt2) - 1) {
                    dp[i] = min(dp[i], cnt1 + 1 + cnt2 + 1 + dp[i - (j - k)]);
                }
            }
            dp[i] = min(dp[i], cnt1 + (i == j ? 0 : 1 + dp[j - i]));
        }
        return dp[target];
    }
};
