// Source: https://leetcode.com/problems/create-sorted-array-through-instructions/
// Author: Miao Zhang
// Date:   2021-05-25

class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1) {}

    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) const {
        int sums = 0;
        while (i > 0) {
            sums += sums_[i];
            i -= lowbit(i);
        }
        return sums;
    }

private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    vector<int> sums_;
};


class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int kMod = 1e9 + 7;
        int n = instructions.size();
        FenwickTree tree(1e5);
        long res = 0;
        for (int i = 0; i < n; i++) {
            int lt = tree.query(instructions[i] - 1);
            int gt = i - tree.query(instructions[i]);
            res += min(lt, gt);
            tree.update(instructions[i], 1);
        }
        return res % kMod;
    }
};
