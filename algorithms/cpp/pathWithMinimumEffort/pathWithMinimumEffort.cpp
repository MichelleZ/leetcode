// Source: https://leetcode.com/problems/path-with-minimum-effort/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto bfs = [&] (int cost) -> bool {
            queue<pair<int, int>> q;
            vector<int> seen(m * n);
            q.emplace(0, 0);
            seen[0] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (x == m - 1 && y == n - 1) return true;
                for (auto d: dirs) {
                    int dx = x + d[0];
                    int dy = y + d[1];
                    if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
                    if (abs(heights[dx][dy] - heights[x][y]) > cost) continue;
                    if (seen[dx * n + dy]) continue;
                    seen[dx * n + dy]++;
                    q.emplace(dx, dy);
                }
            }
            return false;
        };
        int l = 0;
        int r = 1e6 + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (bfs(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(m * n, INT_MAX / 2);
        q.emplace(0, 0);
        dist[0] = 0;
        while (!q.empty()) {
            auto [d, cur] = q.top();
            q.pop();
            if (cur == m * n - 1) return d;
            if (d > dist[cur]) continue;
            int x = cur / n;
            int y = cur % n;
            for (auto dir: dirs) {
                int dx = x + dir[0];
                int dy = y + dir[1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
                int nxt = dx * n + dy;
                int newd = abs(heights[dx][dy] - heights[x][y]);
                if (max(d, newd) >= dist[nxt]) continue;
                q.emplace(dist[nxt] = max(d, newd), nxt);
            }
        }
        return -1;
    }
};
