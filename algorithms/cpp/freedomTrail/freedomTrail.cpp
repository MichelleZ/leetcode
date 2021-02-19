// Source: https://leetcode.com/problems/freedom-trail/
// Author: Miao Zhang
// Date:   2021-02-19

/*********************************************************
 * dp[i][pos] = min{ dp[i - 1][pos'] + dis(pos, pos')}
 * ath the i-th round, move letter at ring[pos] to 12 o'clock
*********************************************************/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        unordered_map<char, vector<int>> dic;
        for (int i = 0; i < ring.size(); i++) {
            dic[ring[i]].push_back(i);
        }
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int pos: dic[key[0]]) {
            dp[0][pos] = min(dp[0][pos], min(pos, n - pos));
        }
        for (int i = 1; i < m; i++) {
            for (int pos: dic[key[i]]) {
                for (int pre_pos: dic[key[i - 1]]) {
                    dp[i][pos] = min(dp[i][pos], dp[i - 1][pre_pos] + min(abs(pos - pre_pos), n - abs(pos - pre_pos)));
                }
            }
        }
        int res = INT_MAX;
        for (int pos: dic[key[m - 1]]) {
            res = min(res, dp[m - 1][pos]);
        }
        return res + m;
    }
};
