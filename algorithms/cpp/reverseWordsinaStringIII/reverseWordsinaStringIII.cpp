// Source: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author: Miao Zhang
// Date:   2021-02-22

class Solution {
public:
    string reverseWords(string s) {
        int idx = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                std::reverse(s.begin() + idx, s.begin() + i);
                idx = i + 1;
            }
        }
        return s;
    }
};
