// Source: https://leetcode.com/problems/pacific-atlantic-water-flow/
// Author: Miao Zhang
// Date:   2021-02-09

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> p_visited(m, vector<bool>(n, false));
        vector<vector<bool>> a_visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            // left pacific
            dfs(matrix, p_visited, i, 0);
            // right atlantic
            dfs(matrix, a_visited, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            // top pacific
            dfs(matrix, p_visited, 0, j);
            // bottom atlantic
            dfs(matrix, a_visited, m - 1, j);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p_visited[i][j] && a_visited[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d: dirs) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || visited[x][y] || matrix[x][y] < matrix[i][j]) continue;
            dfs(matrix, visited, x, y);
        }
    }
};
