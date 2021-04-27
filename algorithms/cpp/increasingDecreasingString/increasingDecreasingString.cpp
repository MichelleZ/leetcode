// Source: https://leetcode.com/problems/increasing-decreasing-string/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    string sortString(string s) {
        vector<int> cnt(26);
        for (char c: s) cnt[c - 'a']++;
        string res;
        while (res.length() != s.length()) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (--cnt[c - 'a'] >= 0) {
                    res += c;
                }
            }
            for (char c = 'z'; c >= 'a'; c--) {
                if (--cnt[c - 'a'] >= 0) {
                    res += c;
                }
            }
        }
        return res;
    }
};
