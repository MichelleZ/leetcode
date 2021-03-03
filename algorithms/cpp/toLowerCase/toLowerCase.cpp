// Source: https://leetcode.com/problems/to-lower-case/
// Author: Miao Zhang
// Date:   2021-03-03

class Solution {
public:
    string toLowerCase(string str) {
        for (char& c: str) {
            if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        }
        return str;
    }
};
