// Source: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
// Author: Miao Zhang
// Date:   2021-05-07

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        for (int i = 0; i < startTime.size(); i++) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i])
                res++;
        }
        return res;
    }
};
