// Source: https://leetcode.com/problems/sudoku-solver/
// Author: Miao Zhang
// Date:   2021-01-08

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
    
    bool dfs(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = 1; num < 10; num++) {
                        board[i][j] = num + '0';
                        if (isValid(i, j, board) && dfs(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(int x, int y, vector<vector<char>>& board) {
        char val = board[x][y];
        board[x][y] = 'X';
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == val) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            if (board[x][j] == val) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[3 * (x / 3) + i][3 * (y / 3) + j] == val) {
                    return false;
                }
            }
        }
        board[x][y] = val;
        return true;
    }
};
