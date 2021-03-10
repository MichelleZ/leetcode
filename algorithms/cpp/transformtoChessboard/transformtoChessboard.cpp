// Source: https://leetcode.com/problems/transform-to-chessboard/
// Author: Miao Zhang
// Date:   2021-03-10

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j]) == 1) return -1;
            }
        }
        int row = 0, col = 0;
        int cntrow = 0, cntcol = 0;
        for (int i = 0; i < n; i++) {
            row += board[0][i];
            col += board[i][0];
            if (board[0][i] != i % 2) cntrow++; // 0101010...
            if (board[i][0] != i % 2) cntcol++; // 0101010...
        }
        if (row < n / 2 || row > (n + 1) / 2) return -1;
        if (col < n / 2 || col > (n + 1) / 2) return -1;
        int res = 0;
        if (n % 2 == 0) {
            res += min(cntrow, n - cntrow);
            res += min(cntcol, n - cntcol);
        } else {
            if (cntrow % 2 == 1) {
                cntrow = n - cntrow;
            }
            if (cntcol % 2 == 1) {
                cntcol = n - cntcol;
            }
            res = cntrow + cntcol;
        }
        return res / 2;
    }
};
