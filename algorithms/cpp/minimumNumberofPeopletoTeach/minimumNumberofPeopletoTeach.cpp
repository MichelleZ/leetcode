// Source: https://leetcode.com/problems/minimum-number-of-people-to-teach/
// Author: Miao Zhang
// Date:   2021-06-02

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langs;
        for (auto& l: languages) {
            sort(begin(l), end(l));
            langs.emplace_back(begin(l), end(l));
        }
        for (auto& f: friendships) {
            auto& l0 = languages[--f[0]];
            auto& l1 = languages[--f[1]];
            vector<int> common;
            set_intersection(begin(l0), end(l0), begin(l1), end(l1), back_inserter(common));
            if (common.size()) f[0] = f[1] = -1;
        }
        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            vector<int> users(m);
            for (auto& f: friendships) {
                if (f[0] == -1) continue;
                if (!langs[f[0]].count(i)) users[f[0]] = 1;
                if (!langs[f[1]].count(i)) users[f[1]] = 1;
            }
            res = min(res, accumulate(begin(users), end(users), 0));
        }
        return res;
    }
};
