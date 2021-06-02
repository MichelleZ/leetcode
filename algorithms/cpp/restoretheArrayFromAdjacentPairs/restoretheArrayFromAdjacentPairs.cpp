// Source: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_map<int, vector<int>> g;
        for (auto& a: adjacentPairs) {
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        vector<int> res(n);
        for (auto& [u, vs]: g) {
            if (vs.size() == 1) {
                res[0] = u;
                res[1] = vs[0];
                break;
            }
        }
        for (int i = 2; i < n; i++) {
            auto& vs = g[res[i - 1]];
            res[i] = vs[0] == res[i - 2] ? vs[1] : vs[0];
        }
        return res;
    }
};
