// Source: https://leetcode.com/problems/maximum-ice-cream-bars/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        int res = 0;
        for (int c: costs) {
            if (c > coins) break;
            res++;
            coins -= c;
        }
        return res;
    }
};
