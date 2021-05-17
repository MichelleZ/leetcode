// Source: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
// Author: Miao Zhang
// Date:   2021-05-16

/************************************************************
 * p[i], n[i]
 * if arr[i] > 0: p[i] = p[i - 1] + 1
 *                n[i] = n[i] + 1 if n[i] else 0
 * if arr[i] < 0: p[i] = n[i - 1] + 1 if n[i - 1] else 0
 *                n[i] = p[i - 1] + 1
 * arr[i] == 0: p[i] = n[i] = 0
************************************************************/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int p = 0;
        int n = 0;
        int res = 0;
        for (int x: nums) {
            if (x > 0) {
                p++;
                if (n) n++;
            } else if (x < 0) {
                int tmp = p;
                p = n ? n + 1 : 0;
                n = tmp + 1;
            } else {
                p = n = 0;
            }
            res = max(res, p);
        }
        return res;
    }
};
