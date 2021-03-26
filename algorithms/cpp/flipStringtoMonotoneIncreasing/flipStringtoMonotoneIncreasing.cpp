// Source: https://leetcode.com/problems/flip-string-to-monotone-increasing/
// Author: Miao Zhang
// Date:   2021-03-25

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> l(n + 1);
        vector<int> r(n + 1);
        l[0] = S[0] - '0';
        r[n - 1] = '1' - S[n - 1];
        for (int i = 1; i < n; i++) {
            l[i] = l[i - 1] + S[i] - '0';
        }
        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] + '1' - S[i];
        }
        int res = r[0];
        for (int i = 1; i <= n; i++) {
            res = min(res, l[i - 1] + r[i]);
        }
        return res;
    }
};
