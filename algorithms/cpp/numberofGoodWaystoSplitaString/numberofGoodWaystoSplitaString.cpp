// Source: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Author: Miao Zhang
// Date:   2021-05-13

class Solution {
public:
    int numSplits(string s) {
        vector<int> l(26);
        vector<int> r(26);
        int cr = 0;
        for (char c: s) {
            cr += (++r[c - 'a'] == 1);
        }
        int res = 0;
        int cl = 0;
        for (char c: s) {
            cl += (++l[c - 'a'] == 1);
            cr -= (--r[c - 'a'] == 0);
            res += cl == cr;
        }
        return res;
    }
};
