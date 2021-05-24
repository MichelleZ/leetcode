// Source: https://leetcode.com/problems/graph-connectivity-with-threshold/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if (threshold == 0)
            return vector<bool>(queries.size(), true);

        vector<int> p(n + 1);
        iota(begin(p), end(p), 0);
        function<int(int)> find = [&] (int x) {
            return p[x] != x ? p[x] = find(p[x]) : p[x];
        };
        for (int x = threshold + 1; x <= n; x++) {
            if (p[x] == x) {
                for (int y = 2 * x; y <= n; y += x) {
                    p[max(find(x), find(y))] = min(find(x), find(y));
                }
            }
        }
        vector<bool> res;
        for (auto& q: queries) {
            res.push_back(find(q[0]) == find(q[1]));
        }
        return res;
    }
};
