// Source: https://leetcode.com/problems/cherry-pickup/
// Author: Miao Zhang
// Date:   2021-03-05

/*****************************************************************
* 1 and 2
* down and down:  dp[r1 + 1][c1][r2 + 1]
* down and right: dp[r1 + 1][c1][r2]
* right and down: dp[r1][c1 + 1][r2]
* right and down: dp[r1][c1 + 1][r2 + 1]
*****************************************************************/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        N = int(grid.size());
        grid_ = &grid;
        memo_ = vector<vector<vector<int>>>(
                N, vector<vector<int>>(N, vector<int>(N, INT_MIN)));
        return max(0, dp(0, 0, 0));
    }

private:
    vector<vector<vector<int>>> memo_;
    int N;
    vector<vector<int>>* grid_;
    
    int dp(int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        if (r1 >= N || c1 >= N || r2 >= N || c2 >= N || (*grid_)[r1][c1] == -1 || (*grid_)[r2][c2] == -1)
            return INT_MIN;
        else if (r1 == N - 1 && c1 == N - 1) {
            return (*grid_)[r1][c1];
        } else if (memo_[r1][c1][r2] != INT_MIN) {
            return memo_[r1][c1][r2];
        } else {
            int res = (*grid_)[r1][c1];
            if (c1 != c2) res += (*grid_)[r2][c2];
            res += max(max(dp(r1 + 1, c1, r2 + 1), dp(r1 + 1, c1, r2)),
                       max(dp(r1, c1 + 1, r2), dp(r1, c1 + 1, r2 + 1)));
            memo_[r1][c1][r2] = res;
            return res;
        }
    }
};
