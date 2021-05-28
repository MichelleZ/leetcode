// Source: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
// Author: Miao Zhang
// Date:   2021-05-28

class UnionFind {
public:
    UnionFind(int n) : p_(n) {
        iota(begin(p_), end(p_), 0);
    }

    int find(int x) {
        if (p_[x] != x) {
            p_[x] = find(p_[x]);
        }
        return p_[x];
    }

    void merge(int x, int y) {
        int px = p_[x];
        int py = p_[y];
        if (px != py)
            p_[px] = py;
    }

private:
    vector<int> p_;
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i);
        }
        sort(begin(edgeList), end(edgeList), [] (auto& a, auto& b) {
            return a[2] < b[2];
        });
        sort(begin(queries), end(queries), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        vector<bool> res(m);
        UnionFind uf(n);
        int i = 0;
        for (auto& q: queries) {
            while (i < edgeList.size() && edgeList[i][2] < q[2]) {
                uf.merge(uf.find(edgeList[i][0]), uf.find(edgeList[i][1]));
                i++;
            }
            res[q[3]] = uf.find(q[0]) == uf.find(q[1]);
        }
        return res;
    }
};
