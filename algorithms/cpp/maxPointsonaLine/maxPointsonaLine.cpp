// Source: https://leetcode.com/problems/max-points-on-a-line/
// Author: Miao Zhang
// Date:   2021-01-22

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            std::map<std::pair<int, int>, int> count;
            int same_points = 1;
            int max_points = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    same_points++;
                } else {
                    max_points = max(max_points, ++count[getSlope(points, i, j)]);
                }
            }
            res = max(res, max_points + same_points);
        }
        return res;
    }

private:
    std::pair<int, int> getSlope(vector<vector<int>>& points, int i, int j) {
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];
        if (dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        // horizontal line
        if (dy == 0) return {points[i][1], 0};
        // vertical line
        if (dx == 0) return {0, points[j][0]};
        // normal
        const int d = gcd(dx, dy);
        return {dy / d, dx / d};
    }

    int gdc(int m, int n) {
        return n == 0 ? m: gcd(n, m % n);
    }
};
