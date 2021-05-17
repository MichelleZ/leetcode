// Source: https://leetcode.com/problems/count-all-possible-routes/
// Author: Miao Zhang
// Date:   2021-05-16

/*******************************************************************
 * dp[i][fuel]: from start to i
 * dp[i][fuel]: sum(dp[i][f + d]) d = |locations[i] - locations[j]|
*******************************************************************/
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int kMod = 1e9 + 7;
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1));
        dp[start][fuel] = 1;
        for (int f = fuel; f > 0; f--) {
            for (int i = 0; i < n; i++) {
                if (!dp[i][f] || abs(locations[i] - locations[finish]) > f)
                    continue;
                for (int j = 0; j < n; j++) {
                    int d = abs(locations[i] - locations[j]);
                    if (i == j || f < d) continue;
                    dp[j][f - d] = (dp[j][f - d] + dp[i][f]) % kMod;
                }
            }
        }
        return accumulate(begin(dp[finish]), end(dp[finish]), 0LL) % kMod;
    }
};
