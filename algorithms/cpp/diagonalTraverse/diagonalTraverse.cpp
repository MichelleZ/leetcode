// Source: https://leetcode.com/problems/diagonal-traverse/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n);
        vector<vector<int>> dirs{{-1, 1}, {1, -1}};
        int i = 0;
        int j = 0;
        int k = 0;
        for (int idx = 0; idx < m * n; idx++) {
            res[idx] = matrix[i][j];
            i += dirs[k][0];
            j += dirs[k][1];
            if (i >= m) {
                i = m - 1;
                j += 2;
                k = 1 - k;
            }
            if (j >= n) {
                j = n - 1;
                i += 2;
                k = 1 - k;
            }
            if (i < 0) {
                i = 0;
                k = 1 - k;
            }
            if (j < 0) {
                j = 0;
                k = 1 - k;
            }
        }
        return res;
    }
};
