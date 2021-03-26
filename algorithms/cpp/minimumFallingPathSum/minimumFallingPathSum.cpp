// Source: https://leetcode.com/problems/minimum-falling-path-sum/
// Author: Miao Zhang
// Date:   2021-03-26

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int tmp = matrix[i + 1][j];
                if (j - 1 >= 0 && j - 1 < n)
                    tmp = min(tmp, matrix[i + 1][j - 1]);
                if (j + 1 >= 0 && j + 1 < n)
                    tmp = min(tmp, matrix[i + 1][j + 1]);
                matrix[i][j] += tmp;
            }
        }
        return *min_element(begin(matrix.front()), end(matrix.front()));
    }
};
