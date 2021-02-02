// Source: https://leetcode.com/problems/power-of-three/
// Author: Miao Zhang
// Date:   2021-02-02

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double a = log10(n) / log10(3);
        return a == floor(a);
    }
};
