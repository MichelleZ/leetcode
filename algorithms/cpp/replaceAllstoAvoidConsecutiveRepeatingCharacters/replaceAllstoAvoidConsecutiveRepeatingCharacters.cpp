// Source: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
// Author: Miao Zhang
// Date:   2021-05-18

class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') continue;
            for (char c: "abc") {
                if ((i == 0 || s[i - 1] != c) && (i == n - 1 || s[i + 1] != c)) {
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};
