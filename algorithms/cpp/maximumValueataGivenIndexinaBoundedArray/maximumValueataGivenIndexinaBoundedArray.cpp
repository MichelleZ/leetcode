// Source: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum + 1;
        while (l < r) {
            long m = l + (r - l) / 2;
            long t1 = m - index;
            long t2 = m - (n - 1 - index);
            long s1 = (t1 + m) * (index + 1) / 2;
            long s2 = (m + t2) * (n - index) / 2;
            if (t1 <= 0) s1 = (1 + m) * m / 2 + (index - m + 1);
            if (t2 <= 0) s2 = (1 + m) * m / 2 + (n - index - m);
            if (s1 + s2 - m > maxSum) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l - 1;
    }
};
