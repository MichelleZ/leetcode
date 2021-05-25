// Source: https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
// Author: Miao Zhang
// Date:   2021-05-25

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int kMod = 1e9 + 7;
        int n = inventory.size();
        sort(rbegin(inventory), rend(inventory));
        long cur = inventory[0];
        long res = 0;
        long c = 0;
        while (orders) {
            while (c < n && inventory[c] == cur) c++;
            int nxt = c == n ? 0 : inventory[c];
            int cnt = min(static_cast<long>(orders), c * (cur - nxt));
            int t = cur - nxt;
            int r = 0;
            if (orders < c * (cur - nxt)) {
                t = orders / c;
                r = orders % c;
            }
            long nxtp = cur - t;
            res = (res + (cur + nxtp + 1) * t / 2 * c + nxtp * r) % kMod;
            orders -= cnt;
            cur = nxt;
        }
        return res;
    }
};
