// Source: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// Author: Miao Zhang
// Date:   2021-05-18

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += mat[i][j] && rows[i] == 1 && cols[i] == 1;
            }
        }
        return res;
    }
};
