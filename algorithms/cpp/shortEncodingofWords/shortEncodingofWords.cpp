// Source: https://leetcode.com/problems/short-encoding-of-words/
// Author: Miao Zhang
// Date:   2021-03-14

public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (string word: words) {
            for (int k = 1; k < word.size(); k++) {
                s.erase(word.substr(k));
            }
        }
        int res = 0;
        for (string word: s) {
            res += word.size() + 1;
        }
        return res;
    }
};
