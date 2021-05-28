// Source: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Author: Miao Zhang
// Date:   2021-05-28

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(begin(n), end(n)) - '0';
    }
};
