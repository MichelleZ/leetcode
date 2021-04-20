// Source: https://leetcode.com/problems/shift-2d-grid/
// Author: Miao Zhang
// Date:   2021-04-20

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int y = (j + k) % n;
                int x = (i + (j + k) / n) % m;
                res[x][y] = grid[i][j];
            }
        }
        return res;
    }
};
