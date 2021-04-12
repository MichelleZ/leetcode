// Source: https://leetcode.com/problems/maximum-of-absolute-value-expression/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int amax = INT_MIN, amin = INT_MAX;
        int bmax = INT_MIN, bmin = INT_MAX;
        int cmax = INT_MIN, cmin = INT_MAX;
        int dmax = INT_MIN, dmin = INT_MAX;
        for (int i = 0; i < arr1.size(); i++) {
            amax = max(amax, arr1[i] + arr2[i] + i);
            amin = min(amin, arr1[i] + arr2[i] + i);
            bmax = max(bmax, arr1[i] + arr2[i] - i);
            bmin = min(bmin, arr1[i] + arr2[i] - i);
            cmax = max(cmax, arr1[i] - arr2[i] + i);
            cmin = min(cmin, arr1[i] - arr2[i] + i);
            dmax = max(dmax, arr1[i] - arr2[i] - i);
            dmin = min(dmin, arr1[i] - arr2[i] - i);
        }

        return max(max(amax - amin, bmax - bmin), max(cmax - cmin, dmax - dmin));
    }
};
