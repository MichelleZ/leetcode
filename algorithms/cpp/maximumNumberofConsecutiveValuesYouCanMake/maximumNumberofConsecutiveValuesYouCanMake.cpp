// Source: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
// Author: Miao Zhang
// Date:   2021-06-08

/***************************************************
 * [0, x], [y, x + y] x --> x + y
 * y < x + 1
****************************************************/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(begin(coins), end(coins));
        int x = 0;
        for (int& c: coins) {
            if (c > x + 1) break;
            x += c;
        }
        return x + 1;
    }
};
