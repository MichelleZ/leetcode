// Source: https://leetcode.com/problems/set-intersection-size-at-least-two/
// Author: Miao Zhang
// Date:   2021-03-08

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
           if (a[0] != b[0]) return a[0] < b[0];
           return a[1] > b[1];
        });
        vector<int> todo(intervals.size(), 2);
        int res = 0;
        while (!intervals.empty()) {
            auto it = intervals.back();
            intervals.pop_back();
            int t = todo.back();
            todo.pop_back();
            for (int p = it[0]; p < it[0] + t; p++) {
                for (int i = 0; i < intervals.size(); i++) {
                    if (todo[i] && p <= intervals[i][1]) {
                        todo[i]--;
                    }
                }
                res++;
            }
        }
        return res;
    }
};
