// Source: https://leetcode.com/problems/elimination-game/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    int lastRemaining(int n) {
        // interval between adjacent numbers 
        int step = 1;
        // the fist num in every line
        int res = 1;
        while (step * 2 <= n) {
            res += step;
            step *= 2;
            if (step * 2 > n) break;
            if ((n / step) % 2 == 1) {
                res += step;
            }
            step *= 2;
        }
        return res;
    }
};
