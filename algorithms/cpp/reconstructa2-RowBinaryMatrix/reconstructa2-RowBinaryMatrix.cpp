// Source: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
// Author: Miao Zhang
// Date:   2021-04-20

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(n));
        for (int j = 0; j < n; j++) {
            if (colsum[j] == 2) {
                matrix[0][j] = 1;
                matrix[1][j] = 1;
                upper--;
                lower--;
            }
        }
        for (int j = 0; j < n; j++) {
            if (colsum[j] == 1) {
                if (upper > lower) {
                    matrix[0][j] = 1;
                    upper--;
                } else {
                    matrix[1][j] = 1;
                    lower--;
                }
            }
        }
        if (upper != 0 || lower != 0) return {};
        return matrix;
    }
};
