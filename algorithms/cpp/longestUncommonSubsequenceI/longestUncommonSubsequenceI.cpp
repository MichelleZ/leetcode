// Source: https://leetcode.com/problems/longest-uncommon-subsequence-i/
// Author: Miao Zhang
// Date:   2021-02-19

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.length(), b.length());
    }
};
