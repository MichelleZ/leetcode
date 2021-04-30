// Source: https://leetcode.com/problems/queries-on-a-permutation-with-key/
// Author: Miao Zhang
// Date:   2021-04-30

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        iota(begin(p), end(p), 1);
        vector<int> res;
        for (int q: queries) {
            int pos = -1;
            for (int i = 0; i < m; i++) {
                if (p[i] == q) {
                    pos = i;
                    break;
                }
            }
            res.push_back(pos);
            p.erase(p.begin() + pos);
            p.insert(p.begin(), q);
        }
        return res;
    }
};
