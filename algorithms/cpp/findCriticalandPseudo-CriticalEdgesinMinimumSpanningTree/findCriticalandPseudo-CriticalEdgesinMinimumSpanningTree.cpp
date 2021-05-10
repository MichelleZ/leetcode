// Source: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
// Author: Miao Zhang
// Date:   2021-05-10

class UnionFind {
public:
    UnionFind(int n): parent_(n), rank_(n) {
        iota(begin(parent_), end(parent_), 0);
    }

    int Find(int x) {
        return parent_[x] == x ? x : parent_[x] = Find(parent_[x]);
    }

    bool Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (px == py) return false;
        if (rank_[px] == rank_[py]) {
            parent_[px] = py;
            rank_[py]++;
        } else if (rank_[px] > rank_[py]) {
            parent_[py] = px;
        } else {
            parent_[px] = py;
        }
        return true;
    }

private:
    vector<int> parent_, rank_;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(begin(edges), end(edges), [&] (const auto& e1, const auto& e2) {
            if (e1[2] != e2[2]) return e1[2] < e2[2];
            return e1 < e2;
        });

        auto MST = [&] (int ex = -1, int in = -1) -> int {
            UnionFind uf(n);
            int cost = 0;
            int cnt = 0;
            if (in >= 0) {
                cost += edges[in][2];
                uf.Union(edges[in][0], edges[in][1]);
                cnt++;
            }
            for (int i = 0; i < edges.size(); i++) {
                if (i == ex) continue;
                if (!uf.Union(edges[i][0], edges[i][1]))
                    continue;
                cost += edges[i][2];
                cnt++;
            }
            return cnt == n - 1 ? cost : INT_MAX;
        };

        int mincost = MST();
        vector<int> criticals;
        vector<int> pseudos;
        for (int i = 0; i < edges.size(); i++) {
            if (MST(i) > mincost) {
                criticals.push_back(edges[i][3]);
            } else if (MST(-1, i) == mincost) {
                pseudos.push_back(edges[i][3]);
            }
        }
        return {criticals, pseudos};
    }
};

