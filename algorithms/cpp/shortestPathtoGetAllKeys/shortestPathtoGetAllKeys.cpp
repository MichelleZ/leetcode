// Source: https://leetcode.com/problems/shortest-path-to-get-all-keys/
// Author: Miao Zhang
// Date:   2021-03-19

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int all_keys = 0;
        queue<int> q;
        vector<vector<vector<int>>> seen(m, vector<vector<int>>(n, vector<int>(64, 0)));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                const char c = grid[i][j];
                if (c == '@') {
                    q.push((i << 16) | j << 8);
                    seen[i][j][0] = 1;
                } else if (c >= 'a' && c <= 'f') {
                    all_keys |= (1 << (c - 'a'));
                }
            }
        }
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int steps = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int s = q.front();
                q.pop();
                int i = s >> 16;
                int j = (s >> 8) & 0xFF;
                int keys = s & 0xFF;
                if (keys == all_keys) return steps;
                for (auto& d: dirs) {
                    int x = i + d[0];
                    int y = j + d[1];
                    int nkeys = keys;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    char c = grid[x][y];
                    if (c == '#') continue;
                    if (c >= 'A' && c <= 'F' && !(keys & (1 << (c - 'A')))) continue;
                    if (c >= 'a' && c <= 'f') nkeys |= (1 << (c - 'a'));
                    if (seen[x][y][nkeys]) continue;
                    q.push((x << 16) | (y << 8) | nkeys);
                    seen[x][y][nkeys] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};
