// Source: https://leetcode.com/problems/spiral-matrix/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int i = 0, j = 0;
        int di = 0, dj = 1;
        int m = matrix.size(), n = matrix[0].size();
        int tmp;
        for (int x = 0; x < m * n; x++) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = 0;
            if (matrix[(i + di) % matrix.size()][(j + dj) % matrix[0].size()] == 0)
            {
                swap(di, dj);
                dj = -dj;
            }
            i += di;
            j += dj;
        }
        return res;
    }
};
