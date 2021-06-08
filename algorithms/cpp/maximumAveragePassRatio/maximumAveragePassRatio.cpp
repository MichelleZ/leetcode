// Source: https://leetcode.com/problems/maximum-average-pass-ratio/
// Author: Miao Zhang
// Date:   2021-06-08

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        auto ratio = [&] (int i, int delta = 0) {
            return static_cast<double>(classes[i][0] + delta) / (classes[i][1] + delta);
        };
        priority_queue<pair<double, int>> q;
        for (int i = 0; i < n; i++) {
            q.emplace(ratio(i, 1) - ratio(i), i);
        }
        while (extraStudents--) {
            auto [gain, i] = q.top(); q.pop();
            classes[i][0]++;
            classes[i][1]++;
            q.emplace(ratio(i, 1) - ratio(i), i);
        }
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += ratio(i);
        }
        return res / n;
    }
};
