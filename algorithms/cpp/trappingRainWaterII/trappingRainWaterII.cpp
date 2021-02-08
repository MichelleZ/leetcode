// Source: https://leetcode.com/problems/trapping-rain-water-ii/
// Author: Miao Zhang
// Date:   2021-02-08

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        // heightMapval, coordinate:r,c
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    q.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }
        int max_height = INT_MIN;
        int res = 0;
        while (!q.empty()) {
            pair<int, int> ele = q.top();
            q.pop();
            int height = ele.first;
            int i = ele.second / n;
            int j = ele.second % n;
            max_height = max(max_height, height);
            for (auto &d: dirs) {
                int x = i + d[0];
                int y = j + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                visited[x][y] = true;
                if (heightMap[x][y] < max_height) {
                    res += max_height - heightMap[x][y];
                }
                q.push({heightMap[x][y], x * n + y});
            }
        }
        return res;
    }
};
