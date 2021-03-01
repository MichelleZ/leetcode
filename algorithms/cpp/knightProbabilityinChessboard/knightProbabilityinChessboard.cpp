// Source: https://leetcode.com/problems/knight-probability-in-chessboard/
// Author: Miao Zhang
// Date:   2021-03-01

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp0(N, vector<double>(N, 0.0));
        dp0[r][c] = 1.0;
        vector<vector<int>> dirs{{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                         {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        for (int k = 0; k < K; k++) {
            vector<vector<double>> dp1(N, vector<double>(N, 0.0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (auto& d: dirs) {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x < 0 || y < 0 || x >= N || y >= N) continue;
                        dp1[i][j] += dp0[x][y];
                    }
                }
            }
            std::swap(dp0, dp1);
        }
        double res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res += dp0[i][j];
            }
        }
        return res / pow(8, K);
    }
};
