// Source: https://leetcode.com/problems/rectangle-area-ii/
// Author: Miao Zhang
// Date:   2021-03-17

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        kMod = 1000000007;
        int OPEN = 0, CLOSE = 1;
        vector<vector<int>> events;
        for (auto& rec: rectangles) {
            events.push_back({rec[1], OPEN, rec[0], rec[2]});
            events.push_back({rec[3], CLOSE, rec[0], rec[2]});
        }
        std::sort(events.begin(), events.end());
        vector<vector<int>> active;
        int cur_y = events[0][0];
        long res = 0;
        for (auto& e: events) {
            res += (query(active) * (e[0] - cur_y)) % kMod;
            if (e[1] == OPEN) {
                active.push_back({e[2], e[3]});
                sort(active.begin(), active.end());
            } else {
                vector<int> tmp{e[2], e[3]};
                auto it = find(active.begin(), active.end(), tmp);
                active.erase(it);
            }
            cur_y = e[0];
        }
        return res % kMod;
    }

private:
    int kMod;
    long query(vector<vector<int>>& active) {
        int res = 0;
        int cur = -1;
        for (auto& a: active) {
            cur = max(cur, a[0]);
            res += max(0, a[1] - cur);
            cur = max(cur, a[1]);
        }
        return res % kMod;
    }
};
