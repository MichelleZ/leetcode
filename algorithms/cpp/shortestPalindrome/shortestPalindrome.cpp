// Source: https://leetcode.com/problems/shortest-palindrome/
// Author: Miao Zhang
// Date:   2021-01-26

class Solution {
public:
    string shortestPalindrome(string s) {
        string r(s.rbegin(), s.rend());
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s.substr(0, n - i) == r.substr(i))
                return r.substr(0, i) + s;
        }
        return "";
    }
};
