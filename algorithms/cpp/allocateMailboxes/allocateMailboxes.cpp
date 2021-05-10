// Source: https://leetcode.com/problems/allocate-mailboxes/
// Author: Miao Zhang
// Date:   2021-05-10

/******************************************************************
 * dp[i][k]: 0-i houses, k mail boxes
 * cost(l, r) = cost(l + 1, r - 1) + (house[r] - hourse[l])
 * dp[i][1] = cost(0, i)
 * dp[i][k] = min(dp[p][k - 1] + cost(p + 1, i))
******************************************************************/
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(begin(houses), end(houses));
        vector<vector<int>> cost(n, vector<int>(n));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = cost[i + 1][j - 1] + (houses[j] - houses[i]);
            }
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX / 2));
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
            for (int j = 2; j <= k && j <= i + 1; j++) {
                for (int p = 0; p < i; p++) {
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p + 1][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
