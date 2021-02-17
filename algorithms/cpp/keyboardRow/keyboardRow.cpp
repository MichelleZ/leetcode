// Source: https://leetcode.com/problems/keyboard-row/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        vector<string> res;
        for (auto w: words) {
            for (auto r: rows) {
                if (check(w, r)) {
                    res.push_back(w);
                    break;
                }
            }
        }
        return res;
    }

    bool check(string& word, string& row) {
        for (char c: word) {
            if (row.find(tolower(c)) == string::npos) return false;
        }
        return true;
    }
};
