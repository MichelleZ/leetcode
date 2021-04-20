// Source: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Author: Miao Zhang
// Date:   2021-04-20

/********************************************************
 * matrix[i][j] = sums(rows[i]) + sums(cols[j])
********************************************************/
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m);
        vector<int> cols(n);
        for (auto indice: indices) {
            rows[indice[0]] ^= 1;
            cols[indice[1]] ^= 1;
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += rows[i] ^ cols[j];
            }
        }
        return res;
    }
};
