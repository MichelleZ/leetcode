// Source: https://leetcode.com/problems/check-if-a-string-can-break-another-string/
// Author: Miao Zhang
// Date:   2021-05-06

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        int res1 = 1;
        int res2 = 1;
        for (int i = 0; i < s1.size(); i++) {
            res1 &= (s1[i] <= s2[i]);
            res2 &= (s1[i] >= s2[i]);
        }
        return res1 || res2;
    }
};
