// Source: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
// Author: Miao Zhang
// Date:   2021-04-21

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); i++) {
            auto& v = m[groupSizes[i]];
            v.push_back(i);
            if (v.size() == groupSizes[i]) {
                res.push_back(std::move(v));
            }
        }
        return res;
    }
};
