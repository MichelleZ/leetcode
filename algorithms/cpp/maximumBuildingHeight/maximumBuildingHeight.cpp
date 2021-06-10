// Source: https://leetcode.com/problems/maximum-building-height/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& rs = restrictions;
        rs.push_back({1, 0});
        sort(begin(rs), end(rs));
        if (rs.back()[0] != n)
        rs.push_back({n, n - 1});
        int m = rs.size();
        for (int i = 1; i < m; ++i)
            rs[i][1] = min(rs[i][1], rs[i - 1][1] + rs[i][0] - rs[i - 1][0]);
        for (int i = m - 2; i >= 0; --i)
            rs[i][1] = min(rs[i][1], rs[i + 1][1] - rs[i][0] + rs[i + 1][0]);
        int res = 0;
        for (int i = 1; i < m; ++i) {
            res = max(res, (rs[i][0] - rs[i - 1][0] + rs[i][1] + rs[i - 1][1]) / 2);
    }
        return res;
    }
};
