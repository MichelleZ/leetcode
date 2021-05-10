// Source: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Author: Miao Zhang
// Date:   2021-05-10

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const auto [low, high] = minmax_element(begin(bloomDay), end(bloomDay));
        int l = *low;
        int r = *high + 1;

        auto getBouquets = [&] (int x) {
            int res = 0;
            int cur = 0;
            for (int b: bloomDay) {
                if (b > x) {
                    cur = 0;
                } else if (++cur == k) {
                    res++;
                    cur = 0;
                }
            }
            return res;
        };

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (getBouquets(mid) >= m) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l >= *high + 1 ? -1 : l;
    }
};
