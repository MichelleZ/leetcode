// Source: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int last = INT_MAX;
        while (n) {
            int p = 0;
            int cur = 1;
            while (cur * 3 <= n) {
                cur *= 3;
                p++;
            }
            if (p == last) return false;
            last = p;
            n -= cur;
        }
        return true;
    }
};
