// Source: https://leetcode.com/problems/broken-calculator/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        return 1 + brokenCalc(X, Y % 2 ? Y + 1: Y / 2);
    }
};
