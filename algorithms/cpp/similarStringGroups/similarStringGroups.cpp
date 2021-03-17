// Source: https://leetcode.com/problems/similar-string-groups/
// Author: Miao Zhang
// Date:   2021-03-17

class UnionFind {
public:
    UnionFind(int size) : size_(size), root_(size), rank_(size) {
        iota(begin(root_), end(root_), 0);
    }

    int Find(int n) {
        if (root_[n] != n) {
            root_[n] = Find(root_[n]);
        }
        return root_[n];
    }

    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (px == py) return;
        if (rank_[py] > rank_[px]) {
            swap(px, py);
        } else if (rank_[px] == rank_[py]) {
            rank_[px]++;
        }
        root_[py] = px;
        size_--;
    }

    int Size() {
        return size_;
    }

private:
    int size_;
    vector<int> root_;
    vector<int> rank_;
};


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                if (similar(strs[i], strs[j])) {
                    uf.Union(i, j);
                }
            }
        }
        return uf.Size();
    }

private:
    bool similar(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i] && ++diff > 2) return false;
        }
        return true;
    }
};
