// Source: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for (char& c: s) {
            if (c == '1') ones++;
        }
        int zeros = 0;
        int res = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            res = max(res, zeros + ones);
        }
        return res;
    }
};
