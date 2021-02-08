// Source: https://leetcode.com/problems/longest-palindrome/
// Author: Miao Zhang
// Date:   2021-02-08

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> dic;
        for (auto &c: s) dic[c]++;
        int res = 0;
        for (auto &it: dic) {
            res += it.second / 2 * 2;
        }
        return res < s.size() ? res + 1 : res;
    }
};
