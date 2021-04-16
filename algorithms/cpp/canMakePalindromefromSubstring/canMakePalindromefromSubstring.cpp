// Source: https://leetcode.com/problems/can-make-palindrome-from-substring/
// Author: Miao Zhang
// Date:   2021-04-15

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            dp[i + 1][s[i] - 'a']++;
        }
        vector<bool> res;
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            res.push_back(isPalidrome(dp, l, r, k));
        }
        return res;
    }

private:
    bool isPalidrome(vector<vector<int>>& dp, int l, int r, int k) {
        int oddcnt = 0;
        for (int i = 0; i < 26; i++) {
            if ((dp[r + 1][i] - dp[l][i]) % 2 != 0) {
                oddcnt++;
                if (oddcnt == 2) {
                    k--;
                    oddcnt = 0;
                }
            }
            if (k < 0) return false;
        }
        return true;
    }
};
