// Source: https://leetcode.com/problems/poor-pigs/
// Author: Miao Zhang
// Date:   2021-02-13

/***************************************************************
 * information theory, k = logm N
 * state: m
 * n: the number of bottle
****************************************************************/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(states));
    }
};
