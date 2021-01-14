// Source: https://leetcode.com/problems/set-matrix-zeroes/
// Author: Miao Zhang
// Date:   2021-01-14

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows;
        vector<int> cols;
        int i, j;
        for (i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (i = 0; i < rows.size(); i++) {
            for (j = 0; j < n; j++) {
                matrix[rows[i]][j] = 0;
            }
        }
        for (j = 0; j < cols.size(); j++) {
            for (i = 0; i < m; i++) {
                matrix[i][cols[j]] = 0;
            }
        }
    }
};
