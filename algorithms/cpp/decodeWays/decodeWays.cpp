// Source: https://leetcode.com/problems/decode-ways/
// Author: Miao Zhang
// Date:   2021-01-15

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                dp[i + 1] += dp[i];
            }
            if (i > 0 && s.substr(i - 1, 2) > "09" && s.substr(i - 1, 2) < "27") {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};
