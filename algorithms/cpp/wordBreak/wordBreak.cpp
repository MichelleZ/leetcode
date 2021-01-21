// Source: https://leetcode.com/problems/word-break/
// Author: Miao Zhang
// Date:   2021-01-21

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) {
            return true;
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
