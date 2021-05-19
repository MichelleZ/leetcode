// Source: https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/
// Author: Miao Zhang
// Date:   2021-05-19

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();
        int maxc = 4;
        if (runningCost > maxc * boardingCost) return -1;
        int c = 0;
        int res = -1;
        int profit = 0;
        int maxprofit = 0;
        for (int i = 0; i < n || c > 0; i++) {
            c += (i < n ? customers[i] : 0);
            profit += min(c, maxc) * boardingCost - runningCost;
            c -= min(c, maxc);
            if (profit > maxprofit) {
                maxprofit = profit;
                res = i + 1;
            }
        }
        return res;
    }
};
