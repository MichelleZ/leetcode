// Source: https://leetcode.com/problems/network-delay-time/
// Author: Miao Zhang
// Date:   2021-03-06

/*Bellman-Ford*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int MAX_TIME = 101 * 100;
        vector<int> dist(n, MAX_TIME);
        dist[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            for (auto& t: times) {
                int u = t[0] - 1, v = t[1] - 1, w = t[2];
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
        int res = *max_element(dist.begin(), dist.end());
        return res == MAX_TIME ? -1 : res;
    }
};

/*Floyd_Warshall*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int MAX_TIME = 101 * 100;
        vector<vector<int>> dp(n, vector<int>(n, MAX_TIME));
        for (auto t: times)
            dp[t[0] - 1][t[1] - 1] = t[2];
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int res = *max_element(dp[k - 1].begin(), dp[k - 1].end());
        return res == MAX_TIME ? -1 : res;
    }
};
