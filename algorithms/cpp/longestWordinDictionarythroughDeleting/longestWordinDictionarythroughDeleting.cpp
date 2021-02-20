// Source: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (string str: d) {
            int i = 0;
            for (char c: s) {
                if (i < str.size() && c == str[i]) i++;
            }
            if (i == str.size() && str.size() >= res.size()) {
                if (str.size() > res.size() || str < res) {
                    res = str;
                }
            }
        }
        return res;
    }
};
