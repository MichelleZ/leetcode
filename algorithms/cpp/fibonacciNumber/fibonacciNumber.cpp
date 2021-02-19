// Source: https://leetcode.com/problems/fibonacci-number/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> memo(n + 1, 0);
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[n];
    }
};
