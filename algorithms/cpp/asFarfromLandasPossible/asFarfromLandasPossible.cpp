// Source: https://leetcode.com/problems/as-far-from-land-as-possible/
// Author: Miao Zhang
// Date:   2021-04-15

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = -1;
        queue<int> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) q.push(i * 100 + j);
            }
        }
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front(); q.pop();
                int i = p / 100;
                int j = p % 100;
                if (grid[i][j] == 2) {
                    res = max(res, steps);
                }
                for (auto d: dirs) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0)
                        continue;
                    grid[x][y] = 2;
                    q.push(x * 100 + y);
                }
            }
            steps++;
        }
        return res;
    }
};
