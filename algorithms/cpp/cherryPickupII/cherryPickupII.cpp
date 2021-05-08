// Source: https://leetcode.com/problems/cherry-pickup-ii/
// Author: Miao Zhang
// Date:   2021-05-08

/*******************************************************************
 * dp[x][y1][y2] = max(dp[x + 1][y1'][y2'])
 *                 + grid[x][y1] + (grid[x][y2] if x1 != x2 else 0)
 * y1': y1-1..y1+1, y2': y2-1..y2+1
 * dp[0][0][n - 1]
*******************************************************************/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> cache(m, vector<vector<int>>(n, vector<int>(n, -1)));

        function<int(int, int, int)> dp = [&] (int x, int y1, int y2) {
            if (x < 0 || x >= m || y1 < 0 || y1 >= n || y2 < 0 || y2 >= n) {
                return 0;
            }
            int& res = cache[x][y1][y2];
            if (res != -1) return res;
            int cur = grid[x][y1] + (y1 != y2) * grid[x][y2];
            for (int d1 = -1; d1 <= 1; d1++) {
                for (int d2 = -1; d2 <= 1; d2++) {
                    res = max(res, cur + dp(x + 1, y1 + d1, y2 + d2));
                }
            }
            return res;
        };
        return dp(0, 0, n - 1);
    }
};
