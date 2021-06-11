// Source: https://leetcode.com/problems/replace-all-digits-with-characters/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.length(); i += 2) {
            s[i] = s[i - 1] + s[i] - '0';
        }
        return s;
    }
};
