// Source: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        for (int k = 0; k < 4; k++) {
            vector<vector<int>> tmp(n, vector<int>(m));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    tmp[j][m - 1 - i] = mat[i][j];
                }
            }
            if (tmp == target) return true;
            mat = tmp;
        }
        return false;
    }
};
