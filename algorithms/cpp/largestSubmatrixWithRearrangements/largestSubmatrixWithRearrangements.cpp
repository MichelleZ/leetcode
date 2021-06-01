// Source: https://leetcode.com/problems/largest-submatrix-with-rearrangements/
// Author: Miao Zhang
// Date:   2021-06-01

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j])
                    matrix[i][j] += matrix[i - 1][j];
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            sort(rbegin(matrix[i]), rend(matrix[i]));
            for (int j = 0; j < n; j++) {
                res = max(res, (j + 1) * matrix[i][j]);
            }
        }
        return res;
    }
};
