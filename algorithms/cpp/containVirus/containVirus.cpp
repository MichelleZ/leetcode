// Source: https://leetcode.com/problems/contain-virus/
// Author: Miao Zhang
// Date:   2021-03-06

/* contain bug */
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
                    if (grid[i][j] == 1 && !visited[key]) {
                        unordered_set<int> region{};
                        regions.push_back(region);
                        unordered_set<int> frontier{};
                        frontiers.push_back(frontier);
                        walls.push_back(0);
                        dfs(i, j, visited, regions, frontiers, walls, grid);
                    }
                }
            }
            if (regions.empty()) break;
            
            int maxidx = -1;
            int maxlen = -1;
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
                            if (x >= 0 && x < grid.size() && y > 0 && y <= grid[0].size()) {
                                if (grid[nx][ny] == 0) grid[nx][ny] = 1;
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
        int key = i * grid[0].size() + j;
        if (visited[key]) return;
        visited[key] = 1;
        regions.back().insert(key);
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto d: dirs) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
            if (grid[x][y] == 1) {
                dfs(x, y, visited, regions, frontiers, walls, grid);
            } else if(grid[x][y] == 0) {
                frontiers.back().insert(x * grid[0].size() + y);
                walls.back() += 1;
            }
        }
    }
};
