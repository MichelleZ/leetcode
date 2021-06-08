// Source: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        int ones = 0;
        for (char c: s) {
            if (c == '1') {
                cnt += (++ones == 1);
            } else {
                ones = 0;
            }
        }
        return cnt == 1;
    }
};
