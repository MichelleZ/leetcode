// Source: https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/
// Author: Miao Zhang
// Date:   2021-05-18

class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> idx(10);
        for (int i = 0; i < s.length(); i++) {
            idx[s[i] - '0'].push(i);
        }
        for (char c: t) {
            int d = c - '0';
            if (idx[d].empty()) return false;
            for (int i = 0; i < d; i++) {
                if (!idx[i].empty() && idx[i].front() < idx[d].front())
                    return false;
            }
            idx[d].pop();
        }
        return true;
    }
};
