// Source: https://leetcode.com/problems/split-a-string-in-balanced-strings/
// Author: Miao Zhang
// Date:   2021-04-18

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int balance = 0;
        for (char c: s) {
            if (c == 'L') balance++;
            else balance--;
            if (balance == 0) res++;
        }
        return res;
    }
};
