// Source: https://leetcode.com/problems/tallest-billboard/
// Author: Miao Zhang
// Date:   2021-03-29

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sums = accumulate(begin(rods), end(rods), 0);
        vector<int> dp(sums + 1, -1);
        dp[0] = 0;
        for (int rod: rods) {
            vector<int> cur(dp);
            for (int i = 0; i <= sums - rod; i++) {
                if (cur[i] < 0) continue;
                dp[i + rod] = max(dp[i + rod], cur[i]);
                dp[abs(i - rod)] = max(dp[abs(i - rod)], cur[i] + min(rod, i));
            }
        }
        return dp[0];
    }
};
