// Source: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int res = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int cur = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (cur < res) {
                    res = cur;
                    idx = i;
                }
            }
        }
        return idx;
    }
};
