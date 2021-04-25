// Source: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Author: Miao Zhang
// Date:   2021-04-25

class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while (num) {
            if (num & 1) num--;
            else num >>= 1;
            res++;
        }
        return res;
    }
};
