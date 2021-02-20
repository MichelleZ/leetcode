#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minesweeper/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        r, c = click
        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1), (1, -1), (1, 1), (-1, 1), (-1, -1)]
        if 0 <= r < len(board) and 0 <= c < len(board[0]):
            if board[r][c] == 'M':
                board[r][c] = 'X'
            elif board[r][c] == 'E':
                n = sum(board[r + dx][c + dy] == 'M' for dx, dy in dirs if 0 <= r + dx < len(board) and 0 <= c + dy < len(board[0]))
                board[r][c] = str(n if n else 'B')
                if not n:
                    for dx, dy in dirs:
                        self.updateBoard(board, [r + dx, c + dy])
        return board
