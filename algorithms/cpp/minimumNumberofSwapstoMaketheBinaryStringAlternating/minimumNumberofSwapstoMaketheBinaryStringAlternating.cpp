// Source: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
// Author: Miao Zhang
// Date:   2021-06-15

class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int n0 = count(begin(s), end(s), '0');
        int n1 = count(begin(s), end(s), '1');
        int res = INT_MAX;
        if (n1 == (n + 1) / 2 && n0 == n / 2) {
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] - '0' == i % 2) {
                    diff++;
                }
            }
            res = min(res, diff / 2);
        }
        if (n1 == n / 2 && n0 == (n + 1) / 2) {
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] - '0' != i % 2) {
                    diff++;
                }
            }
            res = min(res, diff / 2);
        }
        return res == INT_MAX ? -1 : res;
    }
};
