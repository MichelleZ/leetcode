// Source: https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> cnta(26);
        vector<int> cntb(26);
        for (char& c: a) cnta[c - 'a']++;
        for (char& c: b) cntb[c - 'a']++;
        int res = INT_MAX;
        for (int c = 0; c < 26; c++) {
            if (c > 0) {
                int change = 0;
                for (int i = c; i < 26; i++) {
                    change += cnta[i];
                }
                for (int i = 0; i < c; i++) {
                    change += cntb[i];
                }
                res = min(res, change);

                change = 0;
                for (int i = c; i < 26; i++) {
                    change += cntb[i];
                }
                for (int i = 0; i < c; i++) {
                    change += cnta[i];
                }
                res = min(res, change);
            }
            int change = 0;
            for (int i = 0; i < 26; i++) {
                if (i != c) {
                    change += cnta[i];
                    change += cntb[i];
                }
            }
            res = min(res, change);
        }
        return res;
    }
};
