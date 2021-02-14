// Source: https://leetcode.com/problems/hamming-distance/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int res = 0;
        while (t) {
            res += t & 1;
            t >>= 1;
        }
        return res;
    }
};
