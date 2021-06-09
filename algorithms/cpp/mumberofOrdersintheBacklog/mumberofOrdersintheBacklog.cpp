// Source: https://leetcode.com/problems/number-of-orders-in-the-backlog/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int kMod = 1e9 + 7;
        map<int64_t, int64_t> buys;
        map<int64_t, int64_t> sells;
        for (auto& order: orders) {
            auto& m = order[2] == 0 ? buys : sells;
            m[order[0]] += order[1];
            while (buys.size() && sells.size()) {
                auto b = rbegin(buys);
                auto s = begin(sells);
                if (b->first < s->first) break;
                int k = min(b->second, s->second);
                if (!(b->second -= k)) buys.erase((++b).base());
                if (!(s->second -= k)) sells.erase(s);
            }
        }
        int64_t res = 0;
        for (auto& [p, c]: buys) res += c;
        for (auto& [p, c]: sells) res += c;
        return res % kMod;
    }
};

