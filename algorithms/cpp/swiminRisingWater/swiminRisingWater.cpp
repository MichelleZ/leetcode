// Source: https://leetcode.com/problems/swim-in-rising-water/
// Author: Miao Zhang
// Date:   2021-03-09

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        q.push({grid[0][0], 0 * n + 0});
        vector<int> seen(n * n);
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        seen[0 * n + 0] = 1;
        while (!q.empty()) {
            auto node = q.top(); q.pop();
            int t = node.first;
            int i = node.second / n;
            int j = node.second % n;
            if (i == n - 1 && j == n - 1) return t;
            for (auto d: dirs) {
                int x = i + d[0];
                int y = j + d[1];
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (seen[x * n + y]) continue;
                seen[x * n + y] = 1;
                q.push({max(t, grid[x][y]), x * n + y});
            }
        }
        return -1;
    }
};
