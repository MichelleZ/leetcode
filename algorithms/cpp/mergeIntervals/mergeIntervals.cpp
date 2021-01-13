// Source: https://leetcode.com/problems/merge-intervals/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (auto it: intervals) {
            if (it[0] <= end) {
                end = max(end, it[1]);
            } else {
                vector<int> tmp;
                tmp.push_back(start);
                tmp.push_back(end);
                res.push_back(tmp);
                start = it[0];
                end = it[1];
            }
        }
        vector<int> tmp;
        tmp.push_back(start);
        tmp.push_back(end);
        res.push_back(tmp);
        return res;
    }
    
    bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
};
