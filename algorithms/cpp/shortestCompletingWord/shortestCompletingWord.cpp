// Source: https://leetcode.com/problems/shortest-completing-word/
// Author: Miao Zhang
// Date:   2021-03-06

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> l(26, 0);
        for (const char ch: licensePlate) {
            if (isalpha(ch)) ++l[tolower(ch) - 'a'];
        }
        string res;
        int min_len = INT_MAX;
        for (auto& word: words) {
            if (word.size() >= min_len) continue;
            if (!matches(l, word)) continue;
            min_len = word.size();
            res = word;
        }
        return res;
    }

    bool matches(vector<int>& l, string& word) {
        vector<int> c(26, 0);
        for (char ch: word) c[tolower(ch) - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (c[i] < l[i]) return false;
        }
        return true;
    }
};
