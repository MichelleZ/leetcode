// Source: https://leetcode.com/problems/count-pairs-of-nodes/
// Author: Miao Zhang
// Date:   2021-06-07

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> nodedegrees(n);
        unordered_map<int, int> edgefreq;
        for (auto& e: edges) {
            sort(begin(e), end(e));
            nodedegrees[--e[0]]++;
            nodedegrees[--e[1]]++;
            edgefreq[(e[0] << 16) | e[1]]++;
        }
        int maxdegree = *max_element(begin(nodedegrees), end(nodedegrees));
        unordered_map<int, int> degreecnt;
        for (int i = 0; i < n; i++) {
            degreecnt[nodedegrees[i]]++;
        }
        vector<int> cnts(maxdegree * 2 + 2);
        for (auto& [d1, c1]: degreecnt) {
            for (auto& [d2, c2]: degreecnt) {
                if (d1 < d2) cnts[d1 + d2] += c1 * c2;
                else if (d1 == d2) cnts[d1 * 2] += c1 * (c1 - 1) / 2;
            }
        }
        for (auto& [k, freq]: edgefreq) {
            int u = k >> 16;
            int v = k & 0xFFFF;
            cnts[nodedegrees[u] + nodedegrees[v]]--;
            cnts[nodedegrees[u] + nodedegrees[v] - freq]++;
        }
        for (int i = cnts.size() - 2; i >= 0; i--) {
            cnts[i] += cnts[i + 1];
        }
        vector<int> res;
        for (int q: queries) {
            res.push_back(cnts[min(q + 1, int(cnts.size() - 1))]);
        }
        return res;
    }
};

