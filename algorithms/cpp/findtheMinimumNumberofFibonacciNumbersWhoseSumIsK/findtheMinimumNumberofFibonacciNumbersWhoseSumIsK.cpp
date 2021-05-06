// Source: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
// Author: Miao Zhang
// Date:   2021-05-05

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 0) return 0;
        int f1 = 1;
        int f2 = 1;
        while (f2 <= k) {
            swap(f1, f2);
            f2 += f1;
        }
        return 1 + findMinFibonacciNumbers(k - f1);
    }
};
