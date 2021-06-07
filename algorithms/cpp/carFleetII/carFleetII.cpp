// Source: https://leetcode.com/problems/car-fleet-ii/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        auto collide = [&] (int i, int j) -> double {
            return static_cast<double>(cars[j][0] - cars[i][0]) / (cars[i][1] - cars[j][1]);
        };
        int n = cars.size();
        vector<double> res(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && (cars[i][1] <= cars[s.top()][1] ||
                                  (s.size() > 1 && collide(i, s.top()) > res[s.top()]))) {
                s.pop();
            }
            res[i] = s.empty() ? -1 : collide(i, s.top());
            s.push(i);
        }
        return res;
    }
};
