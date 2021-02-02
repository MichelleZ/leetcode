// Source: https://leetcode.com/problems/bulb-switcher/
// Author: Miao Zhang
// Date:   2021-02-02

/***********************************************************
 * ith, ith times: change switch
 * At the beginning, off; even: off; odd: on
 * perfect square: 1, 4, 9, 16, 25, 36 
***********************************************************/

class Solution {
public:
    int bulbSwitch(int n) {
        return int(sqrt(n));
    }
};
