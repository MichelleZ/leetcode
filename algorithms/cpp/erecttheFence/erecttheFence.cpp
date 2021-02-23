// Source: https://leetcode.com/problems/erect-the-fence/
// Author: Miao Zhang
// Date:   2021-02-23

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 3) return points;
        sort(points.begin(), points.end(), [](vector<int> &p, vector<int> &q) {
            return p[0] < q[0] || (p[0] == q[0] && p[1] < q[1]);});

        vector<vector<int>> hull;
        for (int i = 0; i < n; i++) {
            while (hull.size() > 1 && is_clockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) hull.pop_back();
            hull.push_back(points[i]);
        }
        if (hull.size() == points.size())
            return hull;

        hull.pop_back();
        for (int i = n - 1; i >= 0; i--) {
            while (hull.size() > 1 && is_clockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) hull.pop_back();
            hull.push_back(points[i]);
        }
        hull.pop_back();
        return hull;
    }

    bool is_clockwise(vector<int> p0, vector<int> p1, vector<int> p2) {
        return (p1[1] - p0[1]) * (p2[0] - p0[0]) >  (p2[1] - p0[1]) * (p1[0] - p0[0]);
    }
};
