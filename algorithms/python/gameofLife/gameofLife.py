#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/game-of-life/
# Author: Miao Zhang
# Date:   2021-01-30

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                lives = 0;
                dirs = [(0, 1), (0, -1), (1, 0), (-1, 0),
                        (1, 1), (1, -1), (-1, 1), (-1, -1),
                        (0, 0)]
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if 0 <= x < m and 0 <= y < n: lives += board[x][y] & 1
                if lives == 3 or lives - board[x][y] == 3: board[x][y] |= 2
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
