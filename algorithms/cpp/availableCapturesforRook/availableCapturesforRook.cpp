// Source: https://leetcode.com/problems/available-captures-for-rook/
// Author: Miao Zhang
// Date:   2021-03-31

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        auto dfs = [&board](int x, int y, int dx, int dy) {
            x += dx;
            y += dy;
            while (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if (board[x][y] == 'p') return 1;
                if (board[x][y] == 'B') break;
                x += dx;
                y += dy;
            }
            return 0;
        };

        int res = 0;
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'R') {
                    for (auto& d: dirs) {
                        res += dfs(i, j, d[0], d[1]);
                    }
                }
            }
        }
        return res;
    }
};
