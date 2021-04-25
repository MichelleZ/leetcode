// Source: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
// Author: Miao Zhang
// Date:   2021-04-25

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> rs; // rating, id
        for (auto& r: restaurants) {
            if ((!veganFriendly|| veganFriendly && r[2]) && r[3] <= maxPrice && r[4] <= maxDistance) {
                rs.emplace_back(r[1], r[0]);
            }
        }
        sort(rbegin(rs), rend(rs));
        vector<int> res;
        for (auto& r: rs) res.push_back(r.second);
        return res;
    }
};
