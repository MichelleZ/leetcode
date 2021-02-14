// Source: https://leetcode.com/problems/unique-substrings-in-wraparound-string/
// Author: Miao Zhang
// Date:   2021-02-14

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26, 0);
        int n = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
                n++;
            } else {
                n = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], n);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
