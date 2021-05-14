// Source: https://leetcode.com/problems/string-compression-ii/
// Author: Miao Zhang
// Date:   2021-05-14

/********************************************************************
 * dp(i, k, p, l)
 * delete i: dp(i + 1, k - 1, p, l)
 * s[i] == p: carry + dp(i + 1, k, p, l)
 * s[i] != p: 1 + dp(i + 1, k, s[i], 1)
 ******************************************************
 * dp(i, k)
 * delete i: dp(i + 1, k - 1)
 * keep: i -- j: keep s[i], delete != s[i]
 *       encode(sum(s[i-j]==s[i])) + dp(j + 1, k - (s[i-j]!=s[i]))
********************************************************************/
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        vector<vector<int>> cache(n, vector<int>(k + 1, -1));

        function<int(int, int)> dp = [&] (int i, int k) -> int {
            if (k < 0) return n;
            if (i + k >= n) return 0;
            int& res = cache[i][k];
            if (res != -1) return res;
            res = dp(i + 1, k - 1); // delete
            int len = 0;
            int same = 0;
            int diff = 0;
            for (int j = i; j < n && diff <= k; j++) {
                if (s[j] == s[i]) {
                    same++;
                    if (same <= 2 || same == 10 || same == 100) len++;
                } else {
                    diff++;
                }
                res = min(res, len + dp(j + 1, k - diff));
            }
            return res;
        };
        return dp(0, k);
    }
};
