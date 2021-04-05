// Source: https://leetcode.com/problems/coloring-a-border/
// Author: Miao Zhang
// Date:   2021-04-05

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        dfs(grid, r0, c0, grid[r0][c0], color);
        int m = grid.size();
        int n = grid[0].size();
        for (auto& num: res) {
            int i = num / n;
            int j = num % n;
            grid[i][j] = color;
        }
        return grid;
    }
    
private:
    set<int> visited;
    set<int> res;
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int i, int j, int orgcol, int color) {
        int m = grid.size();
        int n = grid[0].size();
        for (auto& d: dirs) {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == orgcol) {
                if (!visited.count(x * n + y)) {
                    visited.insert(x * n + y);
                    dfs(grid, x, y, orgcol, color);
                }
            } else {
                res.insert(i * n + j);
            }
        }
        return;
    }
};
