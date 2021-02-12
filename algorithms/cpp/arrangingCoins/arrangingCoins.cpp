// Source: https://leetcode.com/problems/arranging-coins/
// Author: Miao Zhang
// Date:   2021-02-11

class Solution {
public:
    int arrangeCoins(int n) {
        long level = 0;
        long cnt = 0;
        while (cnt + level + 1 <= n) {
            level++;
            cnt += level;
        }
        return (int)level;
    }
};
