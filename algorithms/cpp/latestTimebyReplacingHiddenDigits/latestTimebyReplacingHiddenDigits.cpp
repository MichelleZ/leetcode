// Source: https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') time[0] = time[1] >= '4' && time[1] <= '9' ? '1' : '2';
        if (time[1] == '?') time[1] = time[0] == '2' ? '3' : '9';
        if (time[3] == '?') time[3] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};