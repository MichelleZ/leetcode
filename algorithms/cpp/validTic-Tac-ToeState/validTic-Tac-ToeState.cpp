// Source: https://leetcode.com/problems/valid-tic-tac-toe-state/
// Author: Miao Zhang
// Date:   2021-03-11

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x_count = 0;
        int o_count = 0;
        for (string& row: board) {
            for (char c: row) {
                if (c == 'X') x_count++;
                if (c == 'O') o_count++;
            }
        }
        if (o_count != x_count - 1 && o_count != x_count) return false;
        if (win(board, 'X') && o_count != x_count - 1) return false;
        if (win(board, 'O') && x_count != o_count) return false;
        return true;
    }

private:
    bool win(vector<string>& board, char player) {
        for (int i = 0; i < 3; i++) {
            if (player == board[i][0] && player == board[i][1] && player == board[i][2]) return true;
            if (player == board[0][i] && player == board[1][i] && player == board[2][i]) return true;
        }
        if (player == board[0][0] && player == board[1][1] && player == board[2][2]) return true;
        if (player == board[0][2] && player == board[1][1] && player == board[2][0]) return true;
        return false;
    }
};
