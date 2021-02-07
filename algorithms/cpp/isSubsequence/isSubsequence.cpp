// Source: https://leetcode.com/problems/is-subsequence/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int i = 0, j = 0;
        while (j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
            if (i == s.size()) return true;
        }
        return false;
    }
};
