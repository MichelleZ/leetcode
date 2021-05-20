// Source: https://leetcode.com/problems/maximal-network-rank/
// Author: Miao Zhang
// Date:   2021-05-20

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n);
        unordered_set<int> connected;
        for (auto& road: roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
            connected.insert((road[0] << 16) | road[1]);
            connected.insert((road[1] << 16) | road[0]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, degrees[i] + degrees[j] -
                          (connected.count((i << 16) | j) ? 1: 0));
            }
        }
        return res;
    }
};
