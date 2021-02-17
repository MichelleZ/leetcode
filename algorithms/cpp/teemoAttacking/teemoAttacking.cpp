// Source: https://leetcode.com/problems/teemo-attacking/
// Author: Miao Zhang
// Date:   2021-02-17

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int res = 0;
        for (int i = 1; i < timeSeries.size(); i++) {
            res += (timeSeries[i] > timeSeries[i - 1] + duration ? duration : timeSeries[i] - timeSeries[i - 1]);
        }
        return res + duration;
    }
};
