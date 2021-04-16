// Source: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: Miao Zhang
// Date:   2021-04-16

/*****************************************************
 * dp[i][0] = max(dp[i-1][0] + A[i], A[i])
 * dp[i][1] = max(dp[i-1][1] + A[i], dp[i - 1][0])
*****************************************************/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int maxval = *max_element(begin(arr), end(arr));
        if (maxval <= 0) return maxval;
        int dp0 = 0;
        int dp1 = 0;
        int res = 0;
        for (int& a: arr) {
            dp1 = max(dp0, dp1 + a);
            dp0 += a;
            res = max(res, max(dp1, dp0));
            if (dp1 < 0) dp1 = 0;
            if (dp0 < 0) dp0 = 0;
        }
        return res;
    }
};
