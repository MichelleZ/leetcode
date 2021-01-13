// Source: https://leetcode.com/problems/spiral-matrix-ii/
// Author: Miao Zhang
// Date:   2021-01-13

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int di = 0, dj = 1;
        for (int num = 1; num < n * n + 1; num++) {
            res[i][j] = num;
            if (res[(i + di) % n][(j + dj + n) % n] != 0) {
                swap(di, dj);
                dj = -dj;
            }
            i += di;
            j += dj;
        }
        return res;
    }
};
