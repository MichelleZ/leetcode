// Source: https://leetcode.com/problems/car-pooling/
// Author: Miao Zhang
// Date:   2021-04-08

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> res;
        for (auto& t: trips) {
            res.push_back({t[1], t[0]});
            res.push_back({t[2], -t[0]});
        }
        sort(begin(res), end(res));
        for (auto& r: res) {
            capacity -= r.second;
            if (capacity < 0) return false;
        }
        return true;
    }
};
