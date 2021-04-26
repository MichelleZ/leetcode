// Source: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
// Author: Miao Zhang
// Date:   2021-04-26

/************************************************
 * dp[i]: 0...2i-1
 * dp[i - 1]: 0...2(i-1)-1
 * 1 + 2 + 3 + 4.....+ (2i-1)
************************************************/
class Solution {
public:
    int countOrders(int n) {
        int kMod = 1e9 + 7;
        long res = 1;
        for (int i = 2; i <= n; i++) {
            res = res * i * (2 * i - 1) % kMod;
        }
        return res;
    }
};
