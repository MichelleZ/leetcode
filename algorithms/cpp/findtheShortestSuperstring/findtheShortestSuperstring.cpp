// Source: https://leetcode.com/problems/find-the-shortest-superstring/
// Author: Miao Zhang
// Date:   2021-03-27

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = words[j].length();
                for (int k = 1; k <= min(words[i].length(), words[j].length()); k++) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        g[i][j] = words[j].length() - k;
                    }
                }
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) dp[1 << i][i] = words[i].length();
        for (int s = 1; s < (1 << n); s++) {
            for (int j = 0; j < n; j++) {
                if (!(s & (1 << j))) continue;
                int ps = s & ~(1 << j);
                for (int i = 0; i < n; i++) {
                    if (dp[ps][i] + g[i][j] < dp[s][j]) {
                        dp[s][j] = dp[ps][i] + g[i][j];
                        parent[s][j] = i;
                    }
                }
            }
        }

        auto it = min_element(begin(dp.back()), end(dp.back()));
        int j = it - begin(dp.back());
        int s = (1 << n) - 1;
        string res;
        while (s) {
            int i = parent[s][j];
            if (i < 0) res = words[j] + res;
            else res = words[j].substr(words[j].length() - g[i][j]) + res;
            s &= ~(1 << j);
            j = i;
        }
        return res;
    }
};
