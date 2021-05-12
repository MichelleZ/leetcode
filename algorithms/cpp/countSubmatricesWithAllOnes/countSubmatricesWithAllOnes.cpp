// Source: https://leetcode.com/problems/count-submatrices-with-all-ones/
// Author: Miao Zhang
// Date:   2021-05-12

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        auto subMat = [&] (int x, int y) {
            int maxn = n;
            int cnt = 0;
            for (int i = x; i < m; i++) {
                for (int j = y; j < maxn; j++) {
                    if (mat[i][j]) {
                        cnt++;
                    } else {
                        maxn = j;
                    }
                }
            }
            return cnt;
        };
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << subMat(i, j) << endl;
                res += subMat(i, j);
            }
        }
        return res;
    }
};
