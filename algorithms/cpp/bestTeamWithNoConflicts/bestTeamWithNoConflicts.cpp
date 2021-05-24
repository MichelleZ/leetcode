// Source: https://leetcode.com/problems/best-team-with-no-conflicts/
// Author: Miao Zhang
// Date:   2021-05-24

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++) {
            players.emplace_back(ages[i], scores[i]);
        }
        sort(rbegin(players), rend(players));
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (players[i].second <= players[j].second)
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += players[i].second;
        }
        return *max_element(begin(dp), end(dp));
    }
};
