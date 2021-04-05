// Source: https://leetcode.com/problems/matrix-cells-in-distance-order/
// Author: Miao Zhang
// Date:   2021-04-05

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                res.push_back({i, j});
            }
        }
        sort(begin(res), end(res), [r0, c0] (const auto& a, const auto& b) {
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        return res;
    }
};
