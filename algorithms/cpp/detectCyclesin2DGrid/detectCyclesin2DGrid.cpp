// Source: https://leetcode.com/problems/detect-cycles-in-2d-grid/
// Author: Miao Zhang
// Date:   2021-05-15

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> seen(m, vector<int>(n));

        function<bool(int, int, int, int)> dfs = [&] (int i, int j, int pi, int pj) {
            seen[i][j]++;
            for (auto& d: dirs) {
                int x = i + d[0];
                int y = j + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (grid[x][y] != grid[i][j]) continue;
                if (seen[x][y] && x != pi && y != pj) return true;
                if (!seen[x][y] && dfs(x, y, i, j)) return true;
            }
            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!seen[i][j]++ && dfs(i, j, -1, -1)) {
                    cout << i << " " << j;
                    return true;
                }
            }
        }
        return false;
    }
};
