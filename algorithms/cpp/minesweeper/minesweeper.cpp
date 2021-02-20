// Source: https://leetcode.com/problems/minesweeper/
// Author: Miao Zhang
// Date:   2021-02-20

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, 
                                 {1, 1}, {1,-1}, {-1, 1}, {-1, -1}};
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
        } else if (board[r][c] == 'E') {
            int minecnt = 0;
            for (auto d: dirs) {
                int x = r + d[0];
                int y = c + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                    minecnt++;
                }
            }
            if (minecnt > 0) {
                board[r][c] = '0' + minecnt;
            } else {
                board[r][c] = 'B';
                for (auto d: dirs) {
                    int x = r + d[0];
                    int y = c + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        vector<int> tmp{x, y};
                        updateBoard(board, tmp);
                    }
                }
            }
        }
        return board;
    }
};
