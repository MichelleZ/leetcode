// Source: https://leetcode.com/problems/map-of-highest-peak/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    q.emplace(i, j);
                    res[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto d: dirs) {
                int x = i + d[0];
                int y = j + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (res[x][y] != -1) continue;
                res[x][y] = res[i][j] + 1;
                q.emplace(x, y);
            }
        }
        return res;
    }
};
