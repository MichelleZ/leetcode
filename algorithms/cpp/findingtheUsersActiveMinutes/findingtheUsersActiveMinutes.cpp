// Source: https://leetcode.com/problems/finding-the-users-active-minutes/
// Author: Miao Zhang
// Date:   2021-06-09

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k, 0);
        unordered_map<int, set<int>> m;
        for (auto& log: logs) {
            int id = log[0], time = log[1];
            m[id].insert(time);
        }
        for (auto& [id, v]: m) {
            int cnt = v.size();
            if (cnt <= k) {
                res[cnt - 1] += 1;
            }
        }
        return res;
    }
};
