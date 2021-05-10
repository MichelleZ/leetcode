// Source: https://leetcode.com/problems/avoid-flood-in-the-city/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        unordered_map<int, int> full;
        set<int> dry;
        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake > 0) {
                if (full.count(lake)) {
                    auto it = dry.upper_bound(full[lake]);
                    if (it == end(dry)) return {};
                    res[*it] = lake;
                    dry.erase(it);
                }
                full[lake] = i;
            } else {
                dry.insert(i);
                res[i] = 1;
            }
        }
        return res;
    }
};
