// Source: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> seen(m * n);

        function<void(int, int)> dfs = [&] (int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n) return;
            if (grid[x][y] == 0) return;
            if (seen[x * n + y]++) return;
            for (auto& d: dirs) {
                int dx = x + d[0];
                int dy = y + d[1];
                dfs(dx, dy);
            }
        };

        function<bool()> disconnected = [&] () {
            int cnt = 0;
            fill(begin(seen), end(seen), 0);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] && !seen[i * n + j]) {
                        dfs(i, j);
                        if (++cnt > 1) return true;
                    }
                }
            }
            if (cnt == 0) return true;
            return false;
        };

        if (disconnected()) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                grid[i][j] = 0;
                if (disconnected()) {
                    return 1;
                }
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};
