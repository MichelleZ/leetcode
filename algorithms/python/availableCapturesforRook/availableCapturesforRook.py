#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/available-captures-for-rook/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        res = 0
        m = len(board)
        n = len(board[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'R':
                    for dx, dy in dirs:
                        x = i + dx
                        y = j + dy
                        while 0 <= x < m and 0 <= y < n:
                            if board[x][y] == 'p':
                                res += 1
                                break
                            if board[x][y] == 'B':
                                break
                            x += dx
                            y += dy 
        return res
