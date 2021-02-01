// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author: Miao Zhang
// Date:   2021-02-01

/******************************************************************
 *         ----
 *         |  | rest  
 *        rest-
 *        /   \
 *    buy/     \rest
 *      /  sell \
 *  hold -------- sold 
 *  |  |
 *  ---- rest 
 * hold[i] = max(hold[i - 1], rest[i - 1] - prices[i])
 * sold[i] = hold[i - 1] + prices[i]
 * rest[i] = max(rest[i - 1], sold[i - 1])
 * init: rest[0] = sold[0] = 0, hold[i] = -MAX
 * res: max(rest[i], sold[i])
******************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;
        int rest = 0;
        int hold = INT_MIN;
        for (auto p: prices) {
            int pre_sold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, pre_sold);
        }
        return max(sold, rest);
    }
};
