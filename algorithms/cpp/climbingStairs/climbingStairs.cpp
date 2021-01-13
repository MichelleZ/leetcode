// Source: https://leetcode.com/problems/climbing-stairs/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};
