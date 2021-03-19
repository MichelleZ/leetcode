// Source: https://leetcode.com/problems/score-after-flipping-matrix/
// Author: Miao Zhang
// Date:   2021-03-19

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    A[i][j] ^= 1;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][j]) cnt++;
            }
            res += (1 << n - 1 - j) * max(cnt, m - cnt);
        }
        return res;
    }
};
