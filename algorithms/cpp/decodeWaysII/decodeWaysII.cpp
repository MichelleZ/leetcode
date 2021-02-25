// Source: https://leetcode.com/problems/decode-ways-ii/
// Author: Miao Zhang
// Date:   2021-02-25

/********************************************
 * dp[0] = 0 if s[0] == '0'
 *       = 9 if s[0] == '*'
 *        = 1 else
 * dp[i] = c(s[i]) * dp[i-1]
 *         c(s[i-1], s[i]) * dp[i - 2]
********************************************/
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        //dp[-1] = 1 dp[0] s[0]
        long long dp[2] ={1, ways(s[0])};
        for (int i = 1; i < s.size(); i++) {
            long long dp_i = ways(s[i]) * dp[1] + ways(s[i - 1], s[i]) * dp[0];
            dp_i %= mod;
            dp[0] = dp[1];
            dp[1] = dp_i;
        }
        return dp[1];
    }

private:
    int mod = 1000000007;
    
    int ways(char c) {
        if (c == '0') return 0;
        if (c == '*') return 9;
        return 1;
    }
    
    int ways(char c1, char c2) {
        if (c1 == '*' && c2 == '*') {
            // 11-19, 21-26
            return 15;
        }
        if (c1 == '*') {
            return (c2 >= '0' && c2 <= '6') ? 2 : 1;
        } else if (c2 == '*') {
            if (c1 == '1') return 9;
            else if (c1 == '2') return 6;
            return 0;
        } else {
            int prefix = (c1 - '0') * 10 + (c2 - '0');
            return prefix >= 10 && prefix <= 26;
        }
    }
};
