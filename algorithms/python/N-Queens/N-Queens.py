#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/n-queens/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        self.dfs(board, n, 0, res)
        return res
    
    def dfs(self, board: List[List[str]], n: int, row: int, res: List[List[str]]):
        if row == n:
            res.append([''.join(i) for i in board])
            return
        for j in range(n):
            if not self.canPlace(row, j, n, board):
                continue
            board[row][j] = 'Q'
            self.dfs(board, n, row + 1, res)
            board[row][j] = '.'
    
    def canPlace(self, row: int, col: int, n: int, board: List[List[str]]):
        '''
              col
            \  |  /
             \ | /
        row:  \|/
        '''
        for i in range(1, row + 1):
            # The same col
            if board[row - i][col] == 'Q':
                return False
            # Positive diagonal
            if col - i >= 0 and board[row - i][col - i] == 'Q':
                return False
            # Negtive diagonal
            if col + i < n and board[row - i][col + i] == 'Q':
                return False
        return True
