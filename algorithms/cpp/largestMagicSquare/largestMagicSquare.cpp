// Source: https://leetcode.com/problems/largest-magic-square/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rows(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            rows[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                rows[i][j] = rows[i][j - 1] + grid[i][j];
            }
        }
        vector<vector<int>> cols(m, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            cols[0][j] = grid[0][j];
            for (int i = 1; i < m; ++i) {
                cols[i][j] = cols[i - 1][j] + grid[i][j];
            }
        }
        for (int l = min(m, n); l >= 2; l--) {
            for (int i = 0; i + l <= m; i++) {
                for (int j = 0; j + l <= n; j++) {
                    int rowsum = rows[i][j + l - 1] - (j ? rows[i][j - 1] : 0);
                    bool check = true;
                    for (int x = i + 1; x < i + l; x++) {
                        if (rows[x][j + l - 1] - (j ? rows[x][j - 1] : 0) != rowsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;
                    for (int y = j + 1; y < j + l; y++) {
                        if (cols[i + l - 1][y] - (i ? cols[i - 1][y] : 0) != rowsum) {
                            check = false;
                            break;
                        }
                    }
                    if (!check) continue;
                    int dia1 = 0, dia2 = 0;
                    for (int k = 0; k < l; k++) {
                        dia1 += grid[i + k][j + k];
                        dia2 += grid[i + k][j + l - 1 - k];
                    }
                    if (dia1 == rowsum && dia2 == rowsum)
                        return l;
                }
            }
        }
        return 1;
    }
};
