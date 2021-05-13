// Source: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
