// Source: https://leetcode.com/problems/tree-of-coprimes/
// Author: Miao Zhang
// Date:   2021-06-04

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int kMax = 50;
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> coprime(kMax + 1);
        for (int i = 1; i <= kMax; i++) {
            for (int j = 1; j <= kMax; j++) {
                if (gcd(i, j) == 1)
                    coprime[i].push_back(j);
            }
        }
        vector<int> res(n, INT_MAX);
        vector<vector<pair<int, int>>> p(kMax + 1);
        function<void(int, int)> dfs = [&] (int cur, int d) {
            int maxd = -1;
            int ancestor = -1;
            for (int c: coprime[nums[cur]]) {
                if (!p[c].empty() && p[c].back().first > maxd) {
                    maxd = p[c].back().first;
                    ancestor = p[c].back().second;
                }
            }
            res[cur] = ancestor;
            p[nums[cur]].emplace_back(d, cur);
            for (int nxt : g[cur]) {
                if (res[nxt] == INT_MAX) dfs(nxt, d + 1);
            }
            p[nums[cur]].pop_back();
        };
        dfs(0, 0);
        return res;
    }
};
