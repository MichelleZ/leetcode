// Source: https://leetcode.com/problems/n-th-tribonacci-number/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            return n == 0 ? 0 : 1;
        }
        int a = 0, b = 1, c = 1;
        int tmp = 0;
        for (int i = 3; i <= n; i++) {
            tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
};
