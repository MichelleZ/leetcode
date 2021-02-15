// Source: https://leetcode.com/problems/generate-random-point-in-a-circle/
// Author: Miao Zhang
// Date:   2021-02-15

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        while (true) {
            double newx = ( 2 * (double)rand() / RAND_MAX - 1.0) * r;
            double newy = ( 2 * (double)rand() / RAND_MAX - 1.0) * r;
            if (newx * newx + newy * newy <= r * r) {
                return {x + newx, y + newy};
            }
        }
    }

private:
    double r, x, y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
