// Source: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: Miao Zhang
// Date:   2021-05-08

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1) return false;
        string_view sv(s);
        unordered_set<string_view> sub;
        for (int i = 0; i + k <= s.size(); i++) {
            sub.insert(sv.substr(i, k));
        }
        return sub.size() == (1 << k);
    }
};
