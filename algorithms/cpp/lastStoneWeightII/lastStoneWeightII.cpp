// Source: https://leetcode.com/problems/last-stone-weight-ii/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<bool> dp(1501);
        dp[0] = true;
        int sums = 0;
        for (int stone: stones) {
            sums += stone;
            for (int i = min(1500, sums); i >= stone; i--) {
                dp[i] = dp[i] | dp[i - stone];
            }
        }
        for (int i = sums / 2; i >= 0; i--) {
            if (dp[i]) return sums - 2 * i;
        }
        return 0;
    }
};
