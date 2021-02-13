// Source: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Author: Miao Zhang
// Date:   2021-02-13

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return {};
        sort(points.begin(), points.end(), cmp);
        int cur_pos = points[0][1];
        int res = 1;
        for (int i = 0; i < points.size(); i++) {
            if (cur_pos >= points[i][0]) {
                continue;
            }
            cur_pos = points[i][1];
            res++;
        }
        return res;
    }
};
