// Source: https://leetcode.com/problems/remove-palindromic-subsequences/
// Author: Miao Zhang
// Date:   2021-04-24

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        if (s == string(rbegin(s), rend(s))) return 1;
        return 2;
    }
};
