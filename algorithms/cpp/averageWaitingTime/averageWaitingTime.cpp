// Source: https://leetcode.com/problems/average-waiting-time/
// Author: Miao Zhang
// Date:   2021-05-29

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int start = 0;
        double sums = 0;
        for (auto& c: customers) {
            if (c[0] > start) start = c[0];
            start += c[1];
            sums += start - c[0];
        }
        return sums / customers.size();
    }
};
