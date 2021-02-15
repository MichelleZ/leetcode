// Source: https://leetcode.com/problems/concatenated-words/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() <= 2) return {};
        unordered_set<string> wordset(words.begin(), words.end());
        vector<string> res;
        for (string word: words) {
            wordset.erase(word);
            int n = word.size();
            if (n == 0) continue;
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && wordset.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp.back()) {
                res.push_back(word);
            }
            wordset.insert(word);
        }
        return res;
    }
};
