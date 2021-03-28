// Source: https://leetcode.com/problems/largest-component-size-by-common-factor/
// Author: Miao Zhang
// Date:   2021-03-28

class DSU {
public:
    DSU(int n): root_(n) {
        for (int i = 0; i < n; i++) root_[i] = i;
    }

    void Union(int x, int y) {
        root_[Find(x)] = Find(y);
    }

    int Find(int x) {
        if (root_[x] != x) root_[x] = Find(root_[x]);
        return root_[x];
    }

private:
    vector<int> root_;
};


class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(begin(A), end(A));
        DSU dsu(n + 1);
        for (int a: A) {
            int t = sqrt(a);
            for (int k = 2; k <= t; k++) {
                if (a % k == 0) {
                    dsu.Union(a, k);
                    dsu.Union(a, a /k);
                }
            }
        }

        unordered_map<int, int> cnt;
        int res = 1;
        for (int a: A) {
            cnt[dsu.Find(a)]++;
        }
        for (auto& c: cnt) {
            res = max(res, c.second);
        }
        return res;
    }
};
