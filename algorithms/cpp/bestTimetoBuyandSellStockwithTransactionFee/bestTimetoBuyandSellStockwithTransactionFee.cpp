// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Author: Miao Zhang
// Date:   2021-03-03

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sold = 0;
        int hold = -prices[0];
        for (auto& p: prices) {
            int tmp = sold;
            sold = max(sold, hold + p - fee);
            hold = max(hold, tmp - p);
        }
        return sold;
    }
};
