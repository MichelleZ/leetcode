// Source: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for (int i = 1; i < 32; i++) {
            if (c & 1) {
                cnt += 1 - ((a | b) & 1);
            } else {
                cnt += (a & 1) + (b & 1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};
