// Source: https://leetcode.com/problems/triangle/
// Author: Miao Zhang
// Date:   2021-01-19

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        //dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i - 1][j - 1]
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MAX));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = triangle[i - 1][j - 1];
                if (i == 1 && j == 1) continue;
                if (j == 1) dp[i][j] += dp[i - 1][j];
                else if(j == i) dp[i][j] += dp[i - 1][j - 1];
                else dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
        
        return *min_element(dp[m].begin(), dp[m].end());
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        //dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i - 1][j - 1]
        vector<vector<int>> dp(2, vector<int>(m + 1, INT_MAX));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= i; j++) {
                dp[1][j] = triangle[i - 1][j - 1];
                if (i == 1 && j == 1) continue;
                if (j == 1) dp[1][j] += dp[0][j];
                else if(j == i) dp[1][j] += dp[0][j - 1];
                else dp[1][j] += min(dp[0][j - 1], dp[0][j]);
            }
            swap(dp[0], dp[1]);
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        //t[i][j] = min(t[i - 1][j - 1], t[i - 1][j])
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0 && j == 0) continue;
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if(j == i) triangle[i][j] += triangle[i - 1][j - 1];
                else triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        
        return *min_element(triangle[m - 1].begin(), triangle[m - 1].end());
    }
};


