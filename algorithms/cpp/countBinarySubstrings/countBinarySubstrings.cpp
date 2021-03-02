// Source: https://leetcode.com/problems/count-binary-substrings/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        int prev = 0;
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                res += min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return res + min(prev, cur);
    }
};
