// Source: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Author: Miao Zhang
// Date:   2021-05-31

class Solution {
public:
    int totalMoney(int n) {
        int remain = n / 7;
        int mod = n % 7;
        // 1+2..+7=28
        // 1+2...+mod
        return (28 * remain) +
               (7 * remain * (remain - 1) / 2) +
               (mod * (mod + 1) / 2) +
               (remain * mod);
    }
};
