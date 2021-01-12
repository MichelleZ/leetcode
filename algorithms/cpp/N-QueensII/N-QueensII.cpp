// Source: https://leetcode.com/problems/n-queens-ii/
// Author: Miao Zhang
// Date:   2021-01-12

class Solution {
public:
    int solveNQueens(int n) {
        vector<vector<string>> res;
        string a;
        for (int i = 0; i < n; i++) a += '.';
        vector<string> board(n, a);
        dfs(board, n, 0, res);
        return res.size();
    }
    
    void dfs(vector<string>& board, int n, int row, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!canPlace(row, j, n, board)) continue;
            board[row][j] = 'Q';
            dfs(board, n, row + 1, res);
            board[row][j] = '.';
        }
    }
    
    bool canPlace(int row, int col, int n, vector<string>& board) {
        for (int i = 1; i < (row + 1); i++) {
            if (board[row - i][col] == 'Q') return false;
            if (col - i >= 0 && board[row - i][col - i] == 'Q') return false;
            if (col + i < n && board[row - i][col + i] == 'Q') return false;
        }
        return true;
    }
};
