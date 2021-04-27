// Source: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int, int>> q;
        vector<int> seen(m * n);
        // left right low up
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        q.push_back({0 * n + 0, 0});
        while (!q.empty()) {
            auto [cur, cost] = q.front();
            q.pop_front();
            int i = cur / n;
            int j = cur % n;
            if (seen[i * n + j]++) continue;
            if (i == m - 1 && j == n - 1) return cost;
            for (int k = 0; k < 4; k++) {
                int x = i + dirs[k][0];
                int y = j + dirs[k][1];
                int xy = x * n + y;
                if (x < 0 || x >= m || y < 0 || y >= n || seen[xy])
                    continue;
                if (grid[i][j] == k + 1) {
                    q.emplace_front(xy, cost);
                } else {
                    q.emplace_back(xy, cost + 1);
                }
            }
        }
        return -1;
    }
};
