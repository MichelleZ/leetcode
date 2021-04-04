// Source: https://leetcode.com/problems/remove-outermost-parentheses/
// Author: Miao Zhang
// Date:   2021-04-03

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int n = 0;
        for (char c: S) {
            if (c == '(' && n++) res += c;
            if (c == ')' && --n) res += c;
        }
        return res;
    }
};
