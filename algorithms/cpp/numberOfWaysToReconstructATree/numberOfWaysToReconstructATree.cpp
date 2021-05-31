// Source: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, bitset<501>> m;
        for (auto& p: pairs) {
            m[p[0]][p[0]] = m[p[1]][p[1]] = m[p[0]][p[1]] = m[p[1]][p[0]] = 1;
        }
        if (!any_of(begin(m), end(m), [&m] (const auto& kv) {
            return kv.second.count() == m.size();
        }))
            return 0;
        int multiple = 0;
        for (auto& p: pairs) {
            const auto& all = m[p[0]] | m[p[1]];
            int r0 = m[p[0]] == all;
            int r1 = m[p[1]] == all;
            if (r0 + r1 == 0) return 0;
            multiple |= r0 * r1;
        }
        return 1 + multiple;
    }
};
