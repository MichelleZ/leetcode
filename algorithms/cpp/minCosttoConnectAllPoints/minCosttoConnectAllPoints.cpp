// Source: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: Miao Zhang
// Date:   2021-05-18

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto dist = [] (const vector<int>& p1, const vector<int>& p2) {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        };
        vector<int> ds(n, INT_MAX);
        for (int i = 1; i < n; i++) {
            ds[i] = dist(points[0], points[i]);
        }
        int res = 0;
        for (int i = 1; i < n; i++) {
            auto it = min_element(begin(ds), end(ds));
            int j = distance(begin(ds), it);
            res += ds[j];
            ds[j] = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (ds[i] == INT_MAX) continue;
                ds[i] = min(ds[i], dist(points[j], points[i]));
            }
        }
        return res;
    }
};
