// Source: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Author: Miao Zhang
// Date:   2021-04-02

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0) + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int d = 1;
            int t = 0;
            for (int w: weights) {
                if ((t += w) > m) {
                    t = w;
                    d++;
                }
            }
            d > D ? l = m + 1 : r = m;
        }
        return l;
    }
};
