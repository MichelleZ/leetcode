// Source: https://leetcode.com/problems/reverse-string-ii/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i <= n / k; i +=2) {
            std:reverse(s.begin() + i * k, s.begin() + min(n, (i + 1) * k));
        }
        return s;
    }
};
