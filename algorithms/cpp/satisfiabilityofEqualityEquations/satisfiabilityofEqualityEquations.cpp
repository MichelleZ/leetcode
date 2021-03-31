// Source: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        iota(begin(root_), end(root_), 0);
        for (const auto& eq: equations) {
            if (eq[1] == '=') {
                root_[find(eq[0])] = find(eq[3]);
            }
        }
        for (const auto& eq: equations) {
            if (eq[1] == '!' && find(eq[0]) == find(eq[3])) {
                return false;
            }
        }
        return true;
    }

private:
    array<int, 128> root_;
    int find(int x) {
        if (x != root_[x]) {
            root_[x] = find(root_[x]);
        }
        return root_[x];
    }
};
