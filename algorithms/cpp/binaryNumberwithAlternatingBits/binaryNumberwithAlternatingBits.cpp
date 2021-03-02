// Source: https://leetcode.com/problems/binary-number-with-alternating-bits/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int r = n & 1;
        while ((n >>= 1) > 0) {
            int t = n & 1;
            if (r == t) return false;
            r = t;
        }
        return true;
    }
};
