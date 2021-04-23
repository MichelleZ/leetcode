// Source: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<int> parent(n);
        iota(begin(parent), end(parent), 0);

        function<int(int)> find = [&] (int x) {
            return parent[x] == x ? parent[x] : parent[x] = find(parent[x]);
        };

        for (auto& c: connections) {
            parent[find(c[0])] = find(c[1]);
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(find(i));
        }

        return s.size() - 1;
    }
};
