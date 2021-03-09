// Source: https://leetcode.com/problems/couples-holding-hands/
// Author: Miao Zhang
// Date:   2021-03-08

class UnionFind {
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        counts = n;
    }

    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    void merge(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        if (rootp == rootq) return;
        parent[rootp] = rootq;
        --counts;
    }

    int getCount(void) {
        return counts;
    }

private:
    vector<int> parent;
    int counts;
};


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        UnionFind uf(row.size() / 2);
        for (int i = 0; i < row.size(); i += 2) {
            uf.merge(row[i] / 2, row[i + 1] / 2);
        }
        return row.size() / 2 - uf.getCount();
    }
};
