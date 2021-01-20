// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author: Miao Zhang
// Date:   2021-01-20

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.size() < 2) return profit;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
