// Source: https://leetcode.com/problems/largest-triangle-area/
// Author: Miao Zhang
// Date:   2021-03-13

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    double a = dist(points[i], points[j]);
                    double b = dist(points[i], points[k]);
                    double c = dist(points[j], points[k]);
                    double s = (a + b + c) / 2;
                    double area = sqrt(s * (s - a) * (s - b) * (s - c));
                    res = max(res, area);
                }
            }
        }
        return res;
    }

private:
    double dist(const vector<int>& p1, const vector<int>& p2) {
        return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
    }
};
