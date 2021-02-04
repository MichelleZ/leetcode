// Source: https://leetcode.com/problems/water-and-jug-problem/
// Author: Miao Zhang
// Date:   2021-02-04

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == z || y == z || x + y == z) return true;
        if (x + y < z) return false;
        return z % gcd(x, y) == 0;
    }
}; 
