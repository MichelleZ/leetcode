// Source: https://leetcode.com/problems/longest-happy-prefix/
// Author: Miao Zhang
// Date:   2021-04-29

/***********************************************************
 * character string hash
 * p system:
 * s = 'abc', a = 1, b = 2, c = 3
 * hash(s) = a * p^2 + b * p^1 + c
************************************************************/
class Solution {
public:
    string longestPrefix(string s) {
        int kMod = 16769023;
        int base = 128;
        int n = s.length();
        int p = 0;
        int q = 0;
        int coe = 1;
        int res = 0;
        for (int i = 1; i < n; i++) {
            p = (p + coe * s[i - 1]) % kMod;
            q = (q * base + s[n - i]) % kMod;
            coe = (coe * base) % kMod;
            if (p == q && s.substr(0, i) == s.substr(n - i))
                res = i;
        }
        return string(s.substr(0, res));
    }
};
