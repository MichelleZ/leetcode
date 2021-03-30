// Source: https://leetcode.com/problems/unique-paths-iii/
// Author: Miao Zhang
// Date:   2021-03-30

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx = -1;
        int sy = -1;
        int n = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) n++;
                else if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        return dfs(grid, sx, sy, n);
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y, int n) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return 0;
        if (grid[x][y] == 2) return n == 0;
        grid[x][y] = -1;
        int paths = dfs(grid, x + 1, y, n - 1) +
                    dfs(grid, x - 1, y, n - 1) +
                    dfs(grid, x, y + 1, n - 1) +
                    dfs(grid, x, y - 1, n - 1);
        grid[x][y] = 0;
        return paths;
    }
};
