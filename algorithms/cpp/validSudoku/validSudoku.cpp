// Source: https://leetcode.com/problems/valid-sudoku/
// Author: Miao Zhang
// Date:   2021-01-08

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<char, int>> row(9, map<char, int>{});
        vector<map<char, int>> col(9, map<char, int>{});
        vector<map<char, int>> cell(9, map<char, int>{});
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int unitnum = 3 * (i / 3) + j / 3;
                int val = board[i][j];
                if (val != '.') {
                    if (row[i].find(val) == row[i].end() && col[j].find(val) == col[j].end() && cell[unitnum].find(val) == cell[unitnum].end()) {
                        row[i][val] = 1;
                        col[j][val] = 1;
                        cell[unitnum][val] = 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
