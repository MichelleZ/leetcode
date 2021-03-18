// Source: https://leetcode.com/problems/car-fleet/
// Author: Miao Zhang
// Date:   2021-03-18

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], static_cast<float>(target - position[i]) / speed[i]};
        }
        sort(rbegin(cars), rend(cars));
        int res{0};
        float max_t{0};
        for (const auto& [p, t]: cars) {
            if (t > max_t) {
                max_t = t;
                res++;
            }
        }
        return res;
    }
};
