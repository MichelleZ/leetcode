// Source: https://leetcode.com/problems/asteroid-collision/
// Author: Miao Zhang
// Date:   2021-03-04

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto a: asteroids) {
            if (a > 0) {
                res.push_back(a);
            } else {
                while (!res.empty() && res.back() > 0 && res.back() < -a) {
                    res.pop_back();
                }
                if (!res.empty() && res.back() == -a) res.pop_back();
                else if (res.empty() || res.back() < 0) res.push_back(a);
            }
        }
        return res;
    }
};
