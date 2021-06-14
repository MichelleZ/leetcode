// Source: https://leetcode.com/problems/minimum-interval-to-include-each-query/
// Author: Miao Zhang
// Date:   2021-06-14

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        sort(begin(intervals), end(intervals), [] (const auto&a, const auto& b) {
            return a[1] > b[1];
        });

        vector<pair<int, int>> qs(m);
        for (int i = 0; i < m; i++) qs[i] = {queries[i], i};
        sort(rbegin(qs), rend(qs));
        vector<int> res(m);
        int j = 0;
        priority_queue<pair<int, int>> q; //{-size, left};
        for (const auto& [query, i]: qs) {
            while (j < n and intervals[j][1] >= query) {
                q.emplace(-(intervals[j][1] - intervals[j][0] + 1), intervals[j][0]);
                j++;
            }
            while (!q.empty() && q.top().second > query) {
                q.pop();
            }
            res[i] = q.empty() ? -1 : -q.top().first;
        }
        return res;
    }
};
