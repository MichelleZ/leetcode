// Source: https://leetcode.com/problems/closest-room/
// Author: Miao Zhang
// Date:   2021-06-11

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size();
        int m = queries.size();
        for (int i = 0; i < m; i++) queries[i].push_back(i);
        sort(begin(rooms), end(rooms), [] (const auto& r1, const auto& r2) {
            return r1[1] > r2[1];

        });
        sort(begin(queries), end(queries), [] (const auto& q1, const auto& q2) {
            return q1[1] > q2[1];

        });
        vector<int> res(m, -1);
        int j = 0;
        set<int> ids;
        for (auto& q: queries) {
            while (j < n && rooms[j][1] >= q[1]) {
                ids.insert(rooms[j++][0]);
            }
            if (ids.empty()) continue;
            int id = q[0];
            auto it = ids.lower_bound(id);
            int id1 = (it != end(ids)) ? *it : INT_MAX;
            int id2 = id1;
            if (it != begin(ids)) id2 = *prev(it);
            res[q[2]] = abs(id1 - id) < abs(id2 - id) ? id1 : id2;
        }
        return res;
    }
};
