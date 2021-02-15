// Source: https://leetcode.com/problems/number-complement/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (num & mask) mask <<= 1;
        return ~num ^ mask;
    }
};
