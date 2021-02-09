// Source: https://leetcode.com/problems/battleships-in-a-board/
// Author: Miao Zhang
// Date:   2021-02-09

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') continue;
                    if (j > 0 && board[i][j - 1] == 'X') continue;
                    res++;
                }
            }
        }
        return res;
    }
};
