// Source: https://leetcode.com/problems/binary-gap/
// Author: Miao Zhang
// Date:   2021-03-19

class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int res = 0;
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                if (last >= 0) {
                    res = max(res, i - last);
                }
                last = i;
            }
        }
        return res;
    }
};
