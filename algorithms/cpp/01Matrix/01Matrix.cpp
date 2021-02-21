// Source: https://leetcode.com/problems/01-matrix/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int val = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto pair = q.front();
                q.pop();
                res[pair.first][pair.second] = val;
                for (auto d: dirs) {
                    int x = pair.first + d[0];
                    int y = pair.second + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == 1) continue;
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
            val++;
        }
        return res;
    }
};
