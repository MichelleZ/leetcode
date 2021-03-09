// Source: https://leetcode.com/problems/reaching-points/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } else {
                if (tx == sx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return tx == sx && ty == sy;
    }
};
