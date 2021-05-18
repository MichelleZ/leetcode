// Source: https://leetcode.com/problems/count-unhappy-friends/
// Author: Miao Zhang
// Date:   2021-05-18

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int> pair(n);
        for (auto& p: pairs) {
            pair[p[0]] = p[1];
            pair[p[1]] = p[0];
        }
        vector<vector<int>> prefer(n, vector<int>(n));
        for (int x = 0; x < n; x++) {
            for (int i = 0; i < preferences[x].size(); i++) {
                prefer[x][preferences[x][i]] = i;
            }
        }
        int res = 0;
        for (int x = 0; x < n; x++) {
            int y = pair[x];
            bool found = false;
            for (int u = 0; u < n && !found; u++) {
                if (u == x || u == y) continue;
                int v = pair[u];
                found |= prefer[x][u] < prefer[x][y] && prefer[u][x] < prefer[u][v];
            }
            if (found) res++;
        }
        return res;
    }
};
