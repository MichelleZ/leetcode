// Source: https://leetcode.com/problems/count-the-number-of-consistent-strings/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> m(26);
        for (char c: allowed) m[c - 'a'] = 1;
        int res = 0;
        for (string& w: words) {
            res += all_of(begin(w), end(w), [&m] (char c) {
                return m[c - 'a'];
            });
        }
        return res;
    }
};
