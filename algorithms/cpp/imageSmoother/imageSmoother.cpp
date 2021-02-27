// Source: https://leetcode.com/problems/image-smoother/
// Author: Miao Zhang
// Date:   2021-02-26

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            res[i][j] += M[x][y];
                            cnt++;
                        }
                    }
                }
                res[i][j] /= cnt;
            }
        }
        return res;
    }
};
