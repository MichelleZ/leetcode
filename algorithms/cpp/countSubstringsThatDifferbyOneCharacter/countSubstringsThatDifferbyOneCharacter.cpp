// Source: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.length();
        int n = t.length();
        int res = 0, diff = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j, diff = 0)
                for (int p = 0; i + p < m && j + p < n && diff <= 1; ++p)
                    if ((diff += (s[i + p] != t[j + p])) == 1) ++res;
        return res;
    }
};
