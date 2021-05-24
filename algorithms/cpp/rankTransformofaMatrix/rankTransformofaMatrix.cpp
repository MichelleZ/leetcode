// Source: https://leetcode.com/problems/rank-transform-of-a-matrix/
// Author: Miao Zhang
// Date:   2021-05-24

class UnionFind {
public:
    UnionFind(int n): p_(n) {
        iota(begin(p_), end(p_), 0);
    }

    int find(int x) {
        if (x != p_[x]) {
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
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rank(m + n);
        map<int, vector<pair<int, int>>> dic;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dic[matrix[i][j]].emplace_back(i, j);
            }
        }
        for (auto& [k, v]: dic) {
            UnionFind uf(m + n);
            vector<int> rank2(rank);
            for (auto& [i, j]: v) {
                int pi = uf.find(i);
                int pj = uf.find(j + m);
                uf.merge(pi, pj);
                rank2[pj] = max(rank2[pi], rank2[pj]);
            }
            for (auto& [i, j]: v) {
                rank[i] = rank[j + m] = matrix[i][j] = rank2[uf.find(i)] + 1;
            }
        }
        return matrix;
    }
};
