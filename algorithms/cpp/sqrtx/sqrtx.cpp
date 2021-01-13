// Source: https://leetcode.com/problems/sqrtx/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l - 1;
    }
};

