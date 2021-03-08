// Source: https://leetcode.com/problems/reach-a-number/
// Author: Miao Zhang
// Date:   2021-03-07

class Solution {
public:
    int reachNumber(int target) {
        target = std::abs(target);
        int k = sqrt(target * 2);
        while (sum(k) < target) ++k;
        int d = sum(k) - target;
        if (d % 2 == 0) return k;
        return k + 1 + (k % 2);
    }

    int sum(int k) {
        return k * (k + 1) / 2;
    }
};
