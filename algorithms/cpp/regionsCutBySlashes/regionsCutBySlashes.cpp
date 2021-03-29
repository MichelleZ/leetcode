// Source: https://leetcode.com/problems/regions-cut-by-slashes/
// Author: Miao Zhang
// Date:   2021-03-29

class DSU {
public:
    DSU(int n): root_(n) {
        for (int i = 0; i < n; i++) {
            root_[i] = i;
        }
    }

    int find(int x) {
        if (root_[x] != x) root_[x] = find(root_[x]);
        return root_[x];
    }

    void merge(int x, int y) {
        root_[find(x)] = find(y);
    }

private:
    vector<int> root_;
};

/***************************************************
 * \ 0 /
 * 3   1
 * / 2 \
 *
***************************************************/
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(4 * n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idx = 4 * (i * n + j);
                if (grid[i][j] == '/') {
                    dsu.merge(idx + 0, idx + 3);
                    dsu.merge(idx + 1, idx + 2);
                } else if (grid[i][j] == '\\') {
                    dsu.merge(idx + 0, idx + 1);
                    dsu.merge(idx + 2, idx + 3);
                } else {
                    dsu.merge(idx + 0, idx + 1);
                    dsu.merge(idx + 1, idx + 2);
                    dsu.merge(idx + 2, idx + 3);
                }

                if (i + 1 < n) {
                    dsu.merge(idx + 2, idx + 4 * n + 0);
                }
                if (j + 1 < n) {
                    dsu.merge(idx + 1, idx + 4 + 3);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 4 * n * n; i++) {
            if (dsu.find(i) == i) res++;
        }
        return res;
    }
};
