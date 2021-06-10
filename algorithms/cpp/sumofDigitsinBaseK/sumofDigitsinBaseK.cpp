// Source: https://leetcode.com/problems/sum-of-digits-in-base-k/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n) {
            res += n % k;
            n /= k;
        }
        return res;
    }
};
