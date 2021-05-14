// Source: https://leetcode.com/problems/can-convert-string-in-k-moves/
// Author: Miao Zhang
// Date:   2021-05-14

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        vector<int> cnt(26);
        for (int i = 0; i < s.length(); i++) {
            int d = (t[i] - s[i] + 26) % 26;
            int c = cnt[d]++;
            if (d != 0 && d + c * 26 > k) {
                return false;
            }
        }
        return true;
    }
};
