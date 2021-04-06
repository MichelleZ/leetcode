// Source: https://leetcode.com/problems/valid-boomerang/
// Author: Miao Zhang
// Date:   2021-04-06

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int dx0 = points[0][0] - points[1][0];
        int dy0 = points[0][1] - points[1][1];
        int dx1 = points[0][0] - points[2][0];
        int dy1 = points[0][1] - points[2][1];
        return dy0 * dx1 != dy1 * dx0;
    }
};
