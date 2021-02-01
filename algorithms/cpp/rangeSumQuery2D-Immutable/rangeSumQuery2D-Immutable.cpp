// Source: https://leetcode.com/problems/range-sum-query-2d-immutable/
// Author: Miao Zhang
// Date:   2021-02-01

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = matrix[i - 1][j - 1] 
                         + dp[i][j - 1]
                         + dp[i - 1][j]
                         - dp[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1]
             - dp[row2 + 1][col1]
             - dp[row1][col2 + 1]
             + dp[row1][col1];
    }
private:
    vector<vector<int>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
