// Source: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int res = 0;
        for (char& c: s) {
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                cnt--;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
