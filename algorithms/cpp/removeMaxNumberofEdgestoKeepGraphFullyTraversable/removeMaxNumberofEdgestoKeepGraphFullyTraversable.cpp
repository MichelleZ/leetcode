// Source: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
// Author: Miao Zhang
// Date:   2021-05-18

class UnionFind {
public:
    UnionFind(int n): p_(n), edges_(0) {
        iota(begin(p_), end(p_), 0);
    }

    int find(int x) {
        if (p_[x] != x) {
            return p_[x] = find(p_[x]);
        }
        return p_[x];
    }

    int merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return 1;
        p_[px] = py;
        edges_++;
        return 0;
    }

    int edges() const {
        return edges_;
    }

private:
    vector<int> p_;
    int edges_;
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res = 0;
        UnionFind a(n + 1), b(n + 1);
        for (const auto& e: edges) {
            if (e[0] != 3) continue;
            res += a.merge(e[1], e[2]);
            b.merge(e[1], e[2]);
        }
        for (const auto& e: edges) {
            if (e[0] == 3) continue;
            UnionFind& uf = e[0] == 1 ? a : b;
            res += uf.merge(e[1], e[2]);
        }
        return (a.edges() == n - 1 && b.edges() == n - 1) ? res : -1;
    }
};
