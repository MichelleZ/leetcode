// Source: https://leetcode.com/problems/number-of-islands/
// Author: Miao Zhang
// Date:   2021-01-25

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int output = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    output += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return output;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        int x = 0;
        int y = 0;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d: dirs) {
            x = i + d[0];
            y = j + d[1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
    }
};
