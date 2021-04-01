// Source: https://leetcode.com/problems/grid-illumination/
// Author: Miao Zhang
// Date:   2021-04-01

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_set<long> s;
        unordered_map<int, int> r, c, dia1, dia2;
        for (const auto& lamp: lamps) {
            int x = lamp[0];
            int y = lamp[1];
            s.insert(static_cast<long>(x) << 32 | y);
            r[x]++;
            c[y]++;
            dia1[x + y]++;
            dia2[x - y]++;
        }
        vector<int> res;
        
        auto dec = [] (unordered_map<int, int>& m, int key) {
            auto it = m.find(key);
            if (it->second == 1)
                m.erase(it);
            else
                --it->second;
        };
        
        for (const auto& query: queries) {
            int x = query[0];
            int y = query[1];
            if (r.count(x) || c.count(y) || dia1.count(x + y) || dia2.count(x - y)) {
                res.push_back(1);
                for (int dx = x - 1; dx <= x + 1; dx++) {
                    for (int dy = y - 1; dy <= y + 1; dy++) {
                        if (dx < 0 || dx >= N || dy < 0 || dy >= N) continue;
                        long key = static_cast<long>(dx) << 32 | dy;
                        auto it = s.find(key);
                        if (it == s.end()) continue;
                        s.erase(it);
                        dec(r, dx);
                        dec(c, dy);
                        dec(dia1, dx + dy);
                        dec(dia2, dx - dy);
                    }
                }
            } else {
                res.push_back(0);
            }
        }
        return res;
    }
};
