// Source: https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        int avg = n;
        for (int i = 0; i < n; i++) {
            int num = 2 * i + 1;
            if (num < n) {
                res += n - num;
            }
        }
        return res;
    }
};
