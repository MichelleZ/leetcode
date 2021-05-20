// Source: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
