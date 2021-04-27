// Source: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m, INT_MAX);
        vector<int> cols(n, INT_MIN);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] = min(rows[i], matrix[i][j]);
                cols[j] = max(cols[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == rows[i] && matrix[i][j] == cols[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};
