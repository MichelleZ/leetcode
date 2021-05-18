// Source: https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
// Author: Miao Zhang
// Date:   2021-05-18

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int sums = cost[0];
        int maxval = cost[0];
        int res = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                res += sums - maxval;
                sums = maxval = 0;
            }
            sums += cost[i];
            maxval = max(maxval, cost[i]);
        }
        return res + (sums - maxval);
    }
};
