// Source: https://leetcode.com/problems/max-value-of-equation/
// Author: Miao Zhang
// Date:   2021-05-11

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q; // {y - x, x}
        q.emplace(0, -1e9);
        int res = INT_MIN;
        for (auto& p: points) {
            int x = p[0], y = p[1];
            while (!q.empty() && x - q.top().second > k) q.pop();
            if (!q.empty()) {
                res = max(res, x + y + q.top().first);
            }
            q.emplace(y - x, x);
        }
        return res;
    }
};
