// Source: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
// Author: Miao Zhang
// Date:   2021-06-01

class UnionFind {
public:
    UnionFind(int n): p_(n) {
        iota(begin(p_), end(p_), 0);
    };

    int find(int x) {
        if (p_[x] != x) {
            p_[x] = find(p_[x]);
        }
        return p_[x];
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            p_[px] = py;
        }
    }
private:
    vector<int> p_;
};


class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);
        for (auto a: allowedSwaps) {
            uf.merge(uf.find(a[0]), uf.find(a[1]));
        }
        unordered_map<int, unordered_multiset<int>> s, t;
        for (int i = 0; i < n; i++) {
            int pi = uf.find(i);
            s[pi].insert(source[i]);
            t[pi].insert(target[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s.find(i) == s.end()) continue;
            for (int x: s[i]) {
                if (t[i].find(x) == t[i].end()) {
                    res++;
                } else {
                    t[i].erase(t[i].find(x));
                }
            }
        }
        return res;
    }
};
