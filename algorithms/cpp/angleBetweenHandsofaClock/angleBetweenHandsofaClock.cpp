// Source: https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Author: Miao Zhang
// Date:   2021-04-25

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_angle = minutes * 360 / 60;
        double hour_angle = (hour + minutes / 60.0) * 360 / 12;
        return min(abs(min_angle - hour_angle), 360 - abs(min_angle - hour_angle));
    }
};
