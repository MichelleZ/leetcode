// Source: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author: Miao Zhang
// Date:   2021-04-19

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int close = count(begin(s), end(s), ')');
        int open = 0;
        string res;

        for (char c: s) {
            if (c == '(') {
                if (open == close) continue;
                open++;
            } else if (c == ')') {
                close--;
                if (open == 0) continue;
                open--;
            }
            res += c;
        }
        return res;
    }
};
