// Source: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        vector<int> seen(m * n, INT_MAX);
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 0);
        seen[0 * n + 0] = 0;
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i, j, val;
                tie(i, j, val) = q.front();
                q.pop();
                if (i == m - 1 && j == n - 1) return steps;
                for (auto d: dirs) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    int v = val + grid[x][y];
                    if (v >= seen[x * n + y] || v > k) continue;
                    seen[x * n + y] = v;
                    q.emplace(x, y, v);
                }
            }
            steps++;
        }
        return -1;
    }
};
