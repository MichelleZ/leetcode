// Source: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
// Author: Miao Zhang
// Date:   2021-04-23

/*************************************************************
 * dp[i][j]: word[0: i], same finger word[i - 1], the other
 * finger j
 * word[i - 1] = p, word[i] = c
 * dp[i+1][j] = dp[i][j] + cost(p, c)
 * dp[i+1][p] = dp[i][j] + cost(j, c)
*************************************************************/
class Solution {
public:
    int minimumDistance(string word) {
        int kRest = 26;
        int n = word.length();
        vector<vector<int>> dp(n + 1, vector<int>(27, INT_MAX / 2));
        dp[0][kRest] = 0;
        auto cost = [&] (int c1, int c2) {
            if (c1 == kRest) return 0;
            return abs(c1 / 6 - c2 / 6) + abs(c1 % 6 - c2 % 6);
        };
        for (int i = 0; i < n; i++) {
            int p = i == 0 ? kRest : word[i - 1] - 'A';
            int c = word[i] - 'A';
            for (int j = 0; j <= 26; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost(p, c));
                dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + cost(j, c));
            }
        }
        return *min_element(begin(dp[n]), end(dp[n]));
    }
};
