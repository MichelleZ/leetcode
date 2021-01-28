// Source: https://leetcode.com/problems/power-of-two/
// Author: Miao Zhang
// Date:   2021-01-28

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        return not (n & (n - 1));
    }
};
