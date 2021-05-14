// Source: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Author: Miao Zhang
// Date:   2021-05-14

class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int close = 0;
        for (char c: s) {
            if (c == ')') {
                if (--close < 0) {
                    res++;
                    close += 2;
                }
            } else {
                if (close & 1) {
                    --close;
                    res++;
                }
                close += 2;
            }
        }
        return res + close;
    }
};
