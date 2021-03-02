// Source: https://leetcode.com/problems/falling-squares/
// Author: Miao Zhang
// Date:   2021-03-02

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> res;
        map<pair<int, int>, int> m;
        int curMax = 0;
        for (auto &pos: positions) {
            vector<vector<int>> t;
            int side_len = pos[1], start = pos[0], end = start + side_len, h = 0;
            auto it = m.upper_bound({start, end});
            if (it != m.begin() && (--it)->first.second <= start) ++it;
            while (it != m.end() && it->first.first < end) {
                if (start > it->first.first) {
                    t.push_back({it->first.first, start, it->second});
                }
                if (end < it->first.second) {
                    t.push_back({end, it->first.second, it->second});
                }
                h = max(h, it->second);
                it = m.erase(it);
            }
            m[{start, end}] = h + side_len;
            for (auto &e: t) m[{e[0], e[1]}] = e[2];
            curMax = max(curMax, h + side_len);
            res.push_back(curMax);
        }
        return res;
    }
};
