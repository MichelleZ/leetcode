// Source: https://leetcode.com/problems/count-number-of-homogenous-substrings/
// Author: Miao Zhang
// Date:   2021-06-03

class Solution {
public:
    int countHomogenous(string s) {
        int kMod = 1e9 + 7;
        int n = s.length();
        long res = 0;
        for (long i = 0, j = 0; i < n; i = j) {
            while (j < n && s[i] == s[j]) j++;
            res += (j - i) * (j - i + 1) / 2;
        }
        return res % kMod;
    }
};
