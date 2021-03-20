// Source: https://leetcode.com/problems/koko-eating-bananas/
// Author: Miao Zhang
// Date:   2021-03-20

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));
        while (l < r) {
            int m = l + (r - l) / 2;
            int h = 0;
            for (int p: piles) {
                h += (p + m - 1) / m;
            }
            if (h <= H) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
