// Source: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Author: Miao Zhang
// Date:   2021-05-16

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles), end(piles));
        int n = piles.size();
        int rounds = n / 3;
        int res = 0;
        int idx = n - 2;
        for (int i = 0; i < rounds; i++) {
            res += piles[idx];
            idx -= 2;
        }
        return res;
    }
};
