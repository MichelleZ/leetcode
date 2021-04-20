// Source: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
// Author: Miao Zhang
// Date:   2021-04-20

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnts(26);
        for (char c: letters) cnts[c - 'a']++;
        vector<int> scores(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (char c: words[i]) {
                scores[i] += score[c - 'a'];
            }
        }
        int res = 0;

        function<void(int, int)> dfs = [&] (int start, int cur) {
            res = max(res, cur);
            for (int i = start; i < words.size(); i++) {
                bool valid = true;
                for (char c: words[i]) valid &= --cnts[c - 'a'] >= 0;
                if (valid)
                    dfs(i + 1, cur + scores[i]);
                for (char c: words[i]) cnts[c - 'a']++;
            }
        };

        dfs(0, 0);
        return res;
    }
};
