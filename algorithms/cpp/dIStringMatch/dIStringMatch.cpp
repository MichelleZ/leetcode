// Source: https://leetcode.com/problems/di-string-match/
// Author: Miao Zhang
// Date:   2021-03-27

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int l = 0;
        int r = S.size();
        for (char c: S) {
            if (c == 'I') {
                res.push_back(l++);
            } else if (c == 'D') {
                res.push_back(r--);
            }
        }
        res.push_back(l);
        return res;
    }
};
