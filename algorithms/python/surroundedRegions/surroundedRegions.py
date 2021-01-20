#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/surrounded-regions/
# Author: Miao Zhang
# Date:   2021-01-20

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return []
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    if board[i][j] == 'O':
                        self.dfs(board, i, j)
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == '#':
                    board[i][j] = 'O'

    
    def dfs(self, board, i, j):
        board[i][j] = '#'
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dx, dy in dirs:
            x = i + dx
            y = j + dy
            if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] == 'O':
                self.dfs(board, x, y)
