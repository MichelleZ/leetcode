#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-sudoku/
# Author: Miao Zhang
# Date:   2021-01-08

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [{}, {}, {}, {}, {},{}, {}, {}, {}]
        col = [{}, {}, {}, {}, {},{}, {}, {}, {}]
        cell = [{}, {}, {}, {}, {},{}, {}, {}, {}]
        
        for i in range(9):
            for j in range(9):
                unitnum = 3 * (i // 3) + j // 3
                val = board[i][j]
                if val != '.':
                    if val not in row[i] and val not in col[j] and val not in cell[unitnum]:
                        row[i][val] = 1
                        col[j][val] = 1
                        cell[unitnum][val] = 1
                    else:
                        return False
        return True
