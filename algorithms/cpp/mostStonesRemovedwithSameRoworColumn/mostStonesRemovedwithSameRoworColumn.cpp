// Source: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: Miao Zhang
// Date:   2021-03-28

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int kSize = 10000;
        UnionFind uf(kSize * 2);
        for (auto& stone: stones) {
            uf.Union(stone[0], stone[1] + kSize);
        }
        unordered_set<int> seen;
        for (const auto& stone: stones) {
            seen.insert(uf.Find(stone[0]));
        }
        return stones.size() - seen.size();
    }

private:
    class UnionFind {
    public:
        UnionFind(int n): root_(n) {
            for (int i = 0; i < n; i++) {
                root_[i] = i;
            }
        }

        void Union(int i, int j) {
            root_[Find(i)] = Find(j);
        }

        int Find(int i) {
            if (root_[i] != i) root_[i] = Find(root_[i]);
            return root_[i];
        }

    private:
        vector<int> root_;
    };
};
