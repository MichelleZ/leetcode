// Source: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        res.reserve(queries.size());
        for (auto& q: queries) {
            int rs = q[2] * q[2];
            int cnt = 0;
            for (auto& p: points) {
                if ((q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]) <= rs)
                    ++cnt;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
