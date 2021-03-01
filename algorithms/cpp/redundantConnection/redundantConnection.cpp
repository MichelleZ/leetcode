// Source: https://leetcode.com/problems/redundant-connection/
// Author: Miao Zhang
// Date:   2021-03-01

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size() + 1, 0);
        vector<int> sizes(edges.size() + 1, 1);
        for (const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if (!parents[u]) parents[u] = u;
            if (!parents[v]) parents[v] = v;
            int pu = find(u, parents);
            int pv = find(v, parents);
            if (pu == pv) return edge;
            if (sizes[pv] > sizes[pu]) {
                swap(pv, pu);
            }
            parents[pv] = pu;
            sizes[pu] += sizes[pv];
        }
        return {};
    }

private:
    int find(int node, vector<int>& parents) {
        while (parents[node] != node) {
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        return node;
    }
};
