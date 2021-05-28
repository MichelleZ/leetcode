// Source: https://leetcode.com/problems/stone-game-vi/
// Author: Miao Zhang
// Date:   2021-05-27

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> sums(n);
        for (int i = 0; i < n; i++) {
            sums.emplace_back(aliceValues[i] + bobValues[i], i);
        }
        sort(rbegin(sums), rend(sums));
        int res = 0;
        for (int i = 0; i < n; i++) {
            int idx = sums[i].second;
            res += (i & 1 ? bobValues[idx] : aliceValues[idx]) * (i & 1 ? -1 : 1);
        }
        return res < 0 ? -1 : (res > 0);
    }
};
