// Source: https://leetcode.com/problems/rank-teams-by-votes/
// Author: Miao Zhang
// Date:   2021-04-27

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string res(votes[0]);
        vector<vector<int>> rank(26, vector<int>(votes[0].size()));
        for (const auto& v: votes) {
            for (int i = 0; i < votes[0].size(); i++) {
                rank[v[i] - 'A'][i]++;
            }
        }
        sort(begin(res), end(res), [&](const char a, const char b) {
            return rank[a - 'A'] == rank[b - 'A'] ? a < b : rank[a - 'A'] > rank[b - 'A'];
        });
        return res;
    }
};
