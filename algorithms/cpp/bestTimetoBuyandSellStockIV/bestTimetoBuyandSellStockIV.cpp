// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Author: Miao Zhang
// Date:   2021-01-25

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        if (k > n / 2) {
            int res = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }
        
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        for (int i = 0; i < k + 1; i++) {
            dp[i][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < k + 1; j++) {
                dp[j - 1][1] = max(dp[j - 1][1], dp[j - 1][0] - prices[i]);
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i]);
            }
        }
        return dp[k][0];
    }
};
