// Source: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
// Author: Miao Zhang
// Date:   2021-06-17

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string target = "01";
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (s[i] != target[i % 2]);
        }
        int res = min({cnt, n - cnt});
        for (int i = 0; i < n; i++) {
            cnt -= (s[i] != target[i % 2]);
            cnt += (s[i] != target[(i + n) % 2]);
            res = min({res, cnt, n - cnt});
        }
        return res;
    }
};
