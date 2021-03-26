// Source: https://leetcode.com/problems/distinct-subsequences-ii/
// Author: Miao Zhang
// Date:   2021-03-27

class Solution {
public:
    int distinctSubseqII(string S) {
        int kMod = 1e9 + 7;
        vector<int> dp(26);
        for (char c: S) {
            dp[c - 'a'] = accumulate(begin(dp), end(dp), 1L) % kMod;
        }
        return accumulate(begin(dp), end(dp), 0L) % kMod;
    }
};
