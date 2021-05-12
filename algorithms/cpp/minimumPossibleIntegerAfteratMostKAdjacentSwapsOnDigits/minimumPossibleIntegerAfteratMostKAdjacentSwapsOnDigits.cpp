// Source: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
// Author: Miao Zhang
// Date:   2021-05-12

class Fenwick {
public:
    Fenwick(int n): sums_(n + 1) {}

    void update(int i , int delta) {
        i++;
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        i++;
        int res = 0;
        while (i > 0) {
            res += sums_[i];
            i -= i & -i;
        }
        return res;
    }

private:
    vector<int> sums_;
};


class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        vector<queue<int>> pos(10);
        for (int i = 0; i < n; i++) {
            pos[num[i] - '0'].push(i);
        }
        Fenwick tree(n);
        vector<int> seen(n);
        string res;
        while (k > 0 && res.size() < n) {
            for (int d = 0; d < 10; d++) {
                if (pos[d].empty()) continue;
                int i = pos[d].front();
                int cost = i - tree.query(i - 1);
                if (cost > k) continue;
                k -= cost;
                res += ('0' + d);
                tree.update(i, 1);
                seen[i] = 1;
                pos[d].pop();
                break;
            }
        }
        for (int i = 0; i < num.size(); i++) {
            if (!seen[i]) res += num[i];
        }
        return res;
    }
};
