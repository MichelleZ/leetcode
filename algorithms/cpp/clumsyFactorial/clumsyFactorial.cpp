// Source: https://leetcode.com/problems/clumsy-factorial/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    int clumsy(int N) {
        if (N <= 0) return 0;
        if (N == 1) return 1;
        if (N == 2) return 2 * 1;
        if (N == 3) return 3 * 2 / 1;

        int res = N * (N - 1) / (N - 2) + (N - 3);
        while ((N -= 4) >= 4) {
            res = res - N * (N - 1) / (N - 2) + (N - 3);
        }
        return res - clumsy(N);
    }
};
