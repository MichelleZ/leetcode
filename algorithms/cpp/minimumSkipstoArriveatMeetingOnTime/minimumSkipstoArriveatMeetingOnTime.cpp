// Source: https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/
// Author: Miao Zhang
// Date:   2021-06-16

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        double eps = 1e-8;
        double INF = 1e9;
        int n = dist.size();
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, INF));
        dp[0][0] = 0.0;

        for (int i = 1; i < n + 1; i ++)
        {
            double t = double(dist[i-1]) / speed;
            for (int j = 0; j < i + 1; j ++)
            {
                if (j < i)
                {
                    dp[i][j] = ceil(dp[i-1][j] + t - eps);
                }
                if (1 <= j)
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + t);
                }
            }
        }

        for (int j = 0; j < n + 1; j ++)
            if (dp[n][j] <= hoursBefore)
                return j;
        return -1;
    }
};
