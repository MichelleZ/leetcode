// Source: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int kMod = 1e9 + 7;
        int m = words[0].length();
        int n = target.length();
        vector<long> dp(n);
        for (int i = 0; i < m; i++) {
            vector<int> cnt(26);
            for (string& word: words) {
                cnt[word[i] - 'a']++;
            }
            for (int j = min(i, n - 1); j >= 0; j--) {
                dp[j] = (dp[j] + (j > 0 ? dp[j - 1] : 1) * cnt[target[j] - 'a']) % kMod;
            }
        }
        return dp[n - 1];
    }
};
