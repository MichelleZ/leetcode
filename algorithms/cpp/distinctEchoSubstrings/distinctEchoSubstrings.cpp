// Source: https://leetcode.com/problems/distinct-echo-substrings/
// Author: Miao Zhang
// Date:   2021-04-23

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.length();
        string_view t(text);
        unordered_set<string_view> s;
        for (int k = 1; k <= n / 2; k++) {
            for (int i = 0; i + k <= n; i++) {
                if (t.substr(i, k) == t.substr(i + k, k)) {
                    s.insert(t.substr(i, 2 * k));
                }
            }
        }
        return s.size();
    }
};
