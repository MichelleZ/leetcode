// Source: https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = x_center - max(x1, min(x2, x_center));
        int dy = y_center - max(y1, min(y2, y_center));
        return dx * dx + dy * dy <= radius * radius;
    }
};
