// Source: https://leetcode.com/problems/sum-of-square-numbers/
// Author: Miao Zhang
// Date:   2021-02-25

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);
        while (a <= b) {
            if (a * a + b * b == c) return true;
            else if (a * a + b * b < c) a++;
            else b--;
        }
        return false;
    }
};
