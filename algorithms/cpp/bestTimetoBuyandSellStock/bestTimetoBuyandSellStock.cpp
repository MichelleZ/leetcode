// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: Miao Zhang
// Date:   2021-01-19

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min_price = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return profit;
    }
};
