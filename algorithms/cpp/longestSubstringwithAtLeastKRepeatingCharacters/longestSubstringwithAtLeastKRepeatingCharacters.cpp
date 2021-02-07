// Source: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Author: Miao Zhang
// Date:   2021-02-07

class Solution {
public:
    int longestSubstring(string s, int k) {
        int cut_index = 0;
        int res = 0;
        int m[128] = {0};
        bool ok = true;
        int n = s.size();
        for (char c: s) m[c]++;
        for (int i = 0; i < n; i++) {
            if (m[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(cut_index, i - cut_index), k));
                ok = false;
                cut_index = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring(s.substr(cut_index, n - cut_index), k));
    }
};
