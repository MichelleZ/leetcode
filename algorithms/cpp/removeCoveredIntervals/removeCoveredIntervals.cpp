// Source: https://leetcode.com/problems/remove-covered-intervals/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [] (const vector<int> a1, const vector<int> a2) {
            return a1[0] == a2[0] ? a2[1] < a1[1] : a1[0] < a2[0];
        });
        int res = 0;
        int prev = 0;
        for (auto it: intervals) {
            if (prev < it[1]) {
                res++;
                prev = it[1];
            }
        }
        return res;
    }
};
