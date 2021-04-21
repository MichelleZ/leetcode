// Source: https://leetcode.com/problems/minimum-falling-path-sum-ii/
// Author: Miao Zhang
// Date:   2021-04-21

/****************************************************
 * dp[i][j] = min(dp[i - 1][k]) + arr[i][j] 0 <= k < n && k != j
 * min(dp[arr.size() - 1][*])
****************************************************/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k != j)
                        x = min(x, arr[i - 1][k]);
                }
                arr[i][j] += x;
            }
        }
        return *min_element(begin(arr.back()), end(arr.back()));
    }
};
