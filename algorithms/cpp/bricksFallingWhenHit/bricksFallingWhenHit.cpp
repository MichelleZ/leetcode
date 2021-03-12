// Source: https://leetcode.com/problems/bricks-falling-when-hit/
// Author: Miao Zhang
// Date:   2021-03-12

class UnionFind {
public:
    UnionFind(int m, int n): m(m), n(n) {
        for (int i = 0; i < m * n + 1; i++) {
            root.push_back(i);
        }
        rank = vector<int>(m * n + 1, 0);
        size = vector<int>(m * n + 1, 1);
    }
    
    int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }
        return root[x];
    }
    
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        if (rank[px] == rank[py]) rank[px]++;
        root[py] = px;
        size[px] += size[py];
    }
    
    int top() {
        return size[find(m * n)] - 1;
    }
    
private:
    int m, n;
    vector<int> root;
    vector<int> rank;
    vector<int> size;
};


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> tmp(grid);
        for (auto h: hits) {
            tmp[h[0]][h[1]] = 0;
        }
        
        UnionFind uf = UnionFind(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp[i][j]) {
                    int idx = index(i, j);
                    if (i == 0) {
                        uf.merge(idx, m * n);
                    }
                    if (i && tmp[i - 1][j]) {
                        uf.merge(idx, index(i - 1, j));
                    }
                    if (j && tmp[i][j - 1]) {
                        uf.merge(idx, index(i, j - 1));
                    }
                }
            }
        }
        
        vector<int> res;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        reverse(hits.begin(), hits.end());
        for (auto h: hits) {
            int r = h[0], c = h[1];
            int pre_roof = uf.top();
            if (grid[r][c] == 0) {
                res.push_back(0);
            } else {
                int idx = index(r, c);
                for (auto d: dirs) {
                    int x = r + d[0];
                    int y = c + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && tmp[x][y]) {
                        uf.merge(idx, index(x, y));
                    }
                }
                if (r == 0) uf.merge(idx, m * n);
                tmp[r][c] = 1;
                res.push_back(max(0, uf.top() - pre_roof - 1));
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    int m, n;
    
    int index(int i, int j) {
        return i * n + j;
    }
    
};
