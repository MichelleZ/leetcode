// Source: https://leetcode.com/problems/largest-1-bordered-square/
// Author: Miao Zhang
// Date:   2021-04-12

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        for (int l = min(m, n); l > 0; l--) {
            for (int x1 = 1, x2 = x1 + l - 1; x2 <= m; x1++, x2++) {
                for (int y1 = 1, y2 = y1 + l - 1; y2 <= n; y1++, y2++) {
                    if (getArea(x1, y1, x2, y1, dp) == l
                        && getArea(x1, y1, x1, y2, dp) == l
                        && getArea(x1, y2, x2, y2, dp) == l
                        && getArea(x2, y1, x2, y2, dp) == l)
                        return l * l;
                }
            }
        }
        return 0;
    }

private:
    int getArea(int x1, int y1, int x2, int y2, vector<vector<int>>& dp) {
        return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
    }
};
