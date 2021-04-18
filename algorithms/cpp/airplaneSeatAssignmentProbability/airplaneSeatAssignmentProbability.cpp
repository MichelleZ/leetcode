// Source: https://leetcode.com/problems/airplane-seat-assignment-probability/
// Author: Miao Zhang
// Date:   2021-04-18

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n > 1 ? 0.5 : 1;
    }
};
