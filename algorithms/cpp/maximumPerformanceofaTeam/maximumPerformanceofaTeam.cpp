// Source: https://leetcode.com/problems/maximum-performance-of-a-team/
// Author: Miao Zhang
// Date:   2021-04-28

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> es;
        for (int i = 0; i < n; i++) {
            es.emplace_back(efficiency[i], speed[i]);
        }
        sort(rbegin(es), rend(es));
        priority_queue<int, vector<int>, greater<int>> q;
        long sums = 0;
        long res = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                sums -= q.top();
                q.pop();
            }
            sums += es[i].second;
            q.push(es[i].second);
            res = max(res, sums * es[i].first);
        }
        return res % static_cast<int>(1e9 + 7);
    }
};
