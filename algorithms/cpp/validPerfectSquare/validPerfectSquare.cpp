// Source: https://leetcode.com/problems/valid-perfect-square/
// Author: Miao Zhang
// Date:   2021-02-04

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num / i; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }
};
