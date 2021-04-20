// Source: https://leetcode.com/problems/number-of-closed-islands/
// Author: Miao Zhang
// Date:   2021-04-20

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool val = 1;
        function<void(int, int)> dfs = [&] (int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n) {
                val = 0;
                return;
            }
            if (grid[x][y]) return;
            grid[x][y] = 1;
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        };
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    val = 1;
                    dfs(i, j);
                    res += val;
                }
            }
        }
        return res;
    }
};
