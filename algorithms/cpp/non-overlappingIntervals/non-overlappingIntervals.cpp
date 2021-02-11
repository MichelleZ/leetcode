// Source: https://leetcode.com/problems/non-overlapping-intervals/
// Author: Miao Zhang
// Date:   2021-02-11

bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int last = 0;
        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[last][1] > intervals[i][0]) {
                if (intervals[i][1] < intervals[last][1]) {
                    last = i;
                }
                res++;
            } else {
                last = i;
            }
        }
        return res;
    }
};
