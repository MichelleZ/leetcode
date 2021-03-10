#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/transform-to-chessboard/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        n = len(board)
        for i in range(n):
            for j in range(n):
                if (board[0][0] ^ board[0][j]^board[i][0]^board[i][j]) == 1:
                    return -1
        row = 0
        col = 0
        cntrow = 0
        cntcol = 0
        for i in range(n):
            row += board[0][i]
            col += board[i][0]
            if board[0][i] != i % 2: cntrow += 1 #010101...
            if board[i][0] != i % 2: cntcol += 1 #010101...
        if row < n // 2 or row > (n + 1) // 2: return -1
        if col < n // 2 or col > (n + 1) // 2: return -1
        res = 0
        if n % 2 == 0:
            res += min(cntrow, n - cntrow)
            res += min(cntcol, n - cntcol)
        else:
            if cntrow % 2 == 1:
                cntrow = n - cntrow
            if cntcol % 2 == 1:
                cntcol = n - cntcol
            res = cntrow + cntcol
        return res // 2
