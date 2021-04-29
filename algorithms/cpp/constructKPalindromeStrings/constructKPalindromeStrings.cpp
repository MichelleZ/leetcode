// Source: https://leetcode.com/problems/construct-k-palindrome-strings/
// Author: Miao Zhang
// Date:   2021-04-29

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        vector<int> cnt(26);
        for (auto& c: s)  cnt[c - 'a'] ^= 1;
        return k >= accumulate(begin(cnt), end(cnt), 0);
    }
};
