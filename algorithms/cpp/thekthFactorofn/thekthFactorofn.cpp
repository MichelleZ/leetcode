// Source: https://leetcode.com/problems/the-kth-factor-of-n/
// Author: Miao Zhang
// Date:   2021-05-11

class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0 && --k == 0) return i;
        }
        return -1;
    }
};
