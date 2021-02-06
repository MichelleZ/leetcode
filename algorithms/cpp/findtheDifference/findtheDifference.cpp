// Source: https://leetcode.com/problems/find-the-difference/
// Author: Miao Zhang
// Date:   2021-02-06

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c: s) res ^= c;
        for (char c: t) res ^= c;
        return res;
    }
};
