// Source: https://leetcode.com/problems/surface-area-of-3d-shapes/
// Author: Miao Zhang
// Date:   2021-03-22

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j]) {
                    res += 2;
                    for (auto& d: dirs){
                        int x = i + d[0];
                        int y = j + d[1];
                        int val = 0;
                        if (x >= 0 && x < grid.size() && y >= 0 && y < grid.size()) {
                            val = grid[x][y];
                        }
                        res += max(grid[i][j] - val, 0);
                    }
                }
            }
        }
        return res;
    }
};
