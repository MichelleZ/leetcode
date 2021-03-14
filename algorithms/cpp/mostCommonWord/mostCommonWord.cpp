// Source: https://leetcode.com/problems/most-common-word/
// Author: Miao Zhang
// Date:   2021-03-14

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> b(banned.begin(), banned.end());
        unordered_map<string, int> counts;
        const string pattern = "!?',;. ";
        int best = 0;
        string res = "";
        int n = paragraph.size();
        string word;
        for (int i = 0; i <= n; i++) {
            if (i == n || pattern.find(paragraph[i]) != string::npos) {
                if (++counts[word] > best && !b.count(word) && word.size() > 0) {
                    best = counts[word];
                    res = word;
                }
                word.clear();
            } else {
                word += tolower(paragraph[i]);
            }
        }
        return res;
    }
};
