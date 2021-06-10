// Source: https://leetcode.com/problems/minimum-sideway-jumps/
// Author: Miao Zhang
// Date:   2021-06-10

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX / 2));
        dp[0][1] = 0;
        dp[0][0] = 1;
        dp[0][2] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(obstacles[i] != 1) dp[i][0] = dp[i-1][0];
            if(obstacles[i] != 2) dp[i][1] = dp[i-1][1];
            if(obstacles[i] != 3) dp[i][2] = dp[i-1][2];
            if(obstacles[i] != 1) dp[i][0] = min(dp[i][0], min(dp[i][1], dp[i][2]) + 1);
            if(obstacles[i] != 2) dp[i][1] = min(dp[i][1], min(dp[i][0], dp[i][2]) + 1);
            if(obstacles[i] != 3) dp[i][2] = min(dp[i][2], min(dp[i][0], dp[i][1]) + 1);

        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};
