// Source: https://leetcode.com/problems/contain-virus/
// Author: Miao Zhang
// Date:   2021-03-06

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        while (true) {
            vector<int> visited(m * n, 0);
            vector<unordered_set<int>> regions;
            vector<unordered_set<int>> frontiers;
            vector<int> walls;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int key = i * n + j;
                    if (grid[i][j] == 1 && visited[key] == 0) {
                        regions.push_back(unordered_set<int>());
                        frontiers.push_back(unordered_set<int>());
                        walls.push_back(0);
                        dfs(i, j, visited, regions, frontiers, walls, grid);
                    }
                }
            }
            if (regions.empty()) break;

            int maxidx = 0;
            int maxlen = 0;
            for (int i = 0; i < frontiers.size(); i++) {
                if (frontiers[i].size() > maxlen) {
                    maxlen = frontiers[i].size();
                    maxidx = i;
                }
            }
            res += walls[maxidx];
            for (int i = 0; i < regions.size(); i++) {
                if (i == maxidx) {
                    for (auto r: regions[i]) {
                        grid[r / n][r % n] = 2;
                    }
                } else {
                    for (auto r: regions[i]) {
                        int x = r / n;
                        int y = r % n;
                        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                        for (auto d: dirs) {
                            int nx = x + d[0];
                            int ny = y + d[1];
                            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0) {
                                grid[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

private:
    void dfs(int i, int j, vector<int>& visited,
             vector<unordered_set<int>>& regions,
             vector<unordered_set<int>>& frontiers, vector<int>& walls,
             vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int key = i * n + j;
        if (visited[key] == 1) return;
        visited[key] = 1;
        regions.back().insert(key);
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto d: dirs) {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] == 1) {
                    dfs(x, y, visited, regions, frontiers, walls, grid);
                } else if(grid[x][y] == 0) {
                    frontiers.back().insert(x * n + y);
                    walls.back()++;
                }
            }
        }
    }
};
