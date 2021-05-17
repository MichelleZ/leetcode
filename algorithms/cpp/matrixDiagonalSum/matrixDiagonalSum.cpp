// Source: https://leetcode.com/problems/matrix-diagonal-sum/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += mat[i][i] + mat[i][n - 1- i];
        }
        if (n & 1) res -= mat[n / 2][n / 2];
        return res;
    }
};
