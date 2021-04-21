// Source: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1;
        int s = 0;
        while (n) {
            int tmp = n % 10;
            p *= tmp;
            s += tmp;
            n /= 10;
        }
        return p - s;
    }
};
