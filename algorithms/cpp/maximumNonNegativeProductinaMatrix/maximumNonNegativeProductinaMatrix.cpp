// Source: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int kMod = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long>> dpmax(m, vector<long>(n));
        vector<vector<long>> dpmin(m, vector<long>(n));
        dpmax[0][0] = dpmin[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dpmax[i][0] = dpmin[i][0] = dpmin[i - 1][0] * grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dpmax[0][j] = dpmin[0][j] = dpmin[0][j - 1] * grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] > 0) {
                    dpmax[i][j] = max(dpmax[i - 1][j], dpmax[i][j - 1]) * grid[i][j];
                    dpmin[i][j] = min(dpmin[i - 1][j], dpmin[i][j - 1]) * grid[i][j];
                } else {
                    dpmax[i][j] = min(dpmin[i - 1][j], dpmin[i][j - 1]) * grid[i][j];
                    dpmin[i][j] = max(dpmax[i - 1][j], dpmax[i][j - 1]) * grid[i][j];
                }
            }
        }
        return dpmax[m - 1][n - 1] >= 0 ? dpmax[m - 1][n - 1] % kMod : -1;
    }
};
