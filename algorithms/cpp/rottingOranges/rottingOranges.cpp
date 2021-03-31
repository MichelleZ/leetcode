// Source: https://leetcode.com/problems/rotting-oranges/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.emplace(i, j);
            }
        }
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int days = 0;
        while (!q.empty() && fresh) {
            int size = q.size();
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (auto& d: dirs) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
                    fresh--;
                    grid[x][y] = 2;
                    q.emplace(x, y);
                }
            }
            days++;
        }
        return fresh ? -1 : days;
    }
};
