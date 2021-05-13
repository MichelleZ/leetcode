// Source: https://leetcode.com/problems/bulb-switcher-iv/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        int cur = 0;
        for (char c: target) {
            if (c - '0' != cur) {
                cur ^= 1;
                res++;
            }
        }
        return res;
    }
};
