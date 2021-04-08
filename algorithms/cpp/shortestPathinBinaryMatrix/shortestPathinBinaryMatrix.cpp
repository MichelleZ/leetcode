// Source: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Author: Miao Zhang
// Date:   2021-04-08

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        deque<int> q;
        q.push_back(0 * n + 0);
        int step = 0;
        set<int> visited;
        visited.insert(0 * n + 0);
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        while (!q.empty()) {
            int lenq = q.size();
            step++;
            while (lenq--) {
                int node = q.front();
                q.pop_front();
                int i = node / n;
                int j = node % n;
                if (i == n - 1 && j == n - 1) return step;
                for (auto& d: dirs) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || visited.count(x * n + y) || grid[x][y] == 1)
                        continue;
                    q.push_back(x * n + y);
                    visited.insert(x * n + y);
                }
            }
        }
        return -1;
    }
};
