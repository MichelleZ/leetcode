// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author: Miao Zhang
// Date:   2021-01-19

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int first_buy = INT_MIN;
        int first_sell = 0;
        int sec_buy = INT_MIN;
        int sec_sell = 0;
        for (auto p: prices) {
            first_buy = max(first_buy, -p);
            first_sell = max(first_sell, first_buy + p);
            sec_buy = max(sec_buy, first_sell - p);
            sec_sell = max(sec_sell, sec_buy + p);
        }
        return sec_sell;
    }
};
