// Source: https://leetcode.com/problems/max-area-of-island/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j)
                 + dfs(grid, i + 1, j)
                 + dfs(grid, i, j - 1)
                 + dfs(grid, i, j + 1);
    }
};
