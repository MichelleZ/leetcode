// Source: https://leetcode.com/problems/spiral-matrix-iii/
// Author: Miao Zhang
// Date:   2021-03-21

/**********************************************************************
 * 1，1，2，2，3，3，4，4，5，5
 * dirs: -->
 *       | |
 *        --
**********************************************************************/
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0; // east
        int k = 0;
        res.push_back({r0, c0});
        if (res.size() == R * C) return res;
        while (++k) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < k; j++) {
                    r0 += dirs[d][0];
                    c0 += dirs[d][1];
                    if (r0 < 0 || r0 >= R || c0 < 0 || c0 >= C) continue;
                    res.push_back({r0, c0});
                    if (res.size() == R * C) return res;
                }
                d = (d + 1) % 4;
            }
        }
        return res;
    }
};
