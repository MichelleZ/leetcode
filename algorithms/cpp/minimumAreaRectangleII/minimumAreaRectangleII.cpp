// Source: https://leetcode.com/problems/minimum-area-rectangle-ii/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<string> s;
        for (const auto& p: points) {
            s.insert(to_string(p[0]) + ":" + to_string(p[1]));
        }
        double min_area = 1e100;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;
                    auto& p1 = points[i];
                    auto& p2 = points[j];
                    auto& p3 = points[k];
                    int dot = (p2[0] - p1[0]) * (p3[0] - p1[0]) +
                              (p2[1] - p1[1]) * (p3[1] - p1[1]);
                    if (dot != 0) continue;
                    int p4x = p2[0] + p3[0] - p1[0];
                    int p4y = p2[1] + p3[1] - p1[1];
                    if (!s.count(to_string(p4x) + ":" + to_string(p4y))) continue;
                    double a = pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2);
                    double b = pow(p3[0] - p1[0], 2) + pow(p3[1] - p1[1], 2);
                    double area = a * b;
                    min_area = min(min_area, area);
                }
            }
        }
        return min_area < 1e100 ? sqrt(min_area) : 0;
    }
};
