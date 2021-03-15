// Source: https://leetcode.com/problems/consecutive-numbers-sum/
// Author: Miao Zhang
// Date:   2021-03-15

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0, sums = 0;
        for (int i = 1; sums < N; i++) {
            sums += i;
            if ((N - sums) % i == 0) res++;
        }
        return res;
    }
};
