// Source: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int concatenatedBinary(int n) {
        int kMod = 1e9 + 7;
        long res = 0;
        int shift = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                shift++;
            }
            res = ((res << shift) % kMod + i) % kMod;
        }
        return res;
    }
};
