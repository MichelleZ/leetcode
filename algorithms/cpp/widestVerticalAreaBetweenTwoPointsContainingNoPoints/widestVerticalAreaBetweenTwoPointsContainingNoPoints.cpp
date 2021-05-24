// Source: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const auto& p1, const auto& p2) {
           return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
        });
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            res = max(res, points[i][0] - points[i - 1][0]);
        }
        return res;
    }
};
