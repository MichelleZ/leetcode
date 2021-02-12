// Source: https://leetcode.com/problems/number-of-boomerangs/
// Author: Miao Zhang
// Date:   2021-02-12

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> dist(points.size());
            for (int j = 0; j < points.size(); j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                dist[dx * dx + dy * dy]++;
            }
            for (auto &d: dist) {
                res += d.second * (d.second - 1);
            }
        }
        return res;
    }
};
