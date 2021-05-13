// Source: https://leetcode.com/problems/water-bottles/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int bottle = numBottles;
        while (bottle >= numExchange) {
            bottle -= numExchange;
            res++;
            bottle++;
        }
        return res;
    }
};
