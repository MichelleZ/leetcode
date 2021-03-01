#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/knight-probability-in-chessboard/
# Author: Miao Zhang
# Date:   2021-03-01

class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        dp = [[0 for _ in range(N)] for _ in range(N)]
        dp[r][c] = 1
        dirs = [(1, 2), (1, -2), (2, 1), (2, -1), (-1, 2), (-1, -2), (-2, 1), (-2, -1)]
        for k in range(K):
            newdp = [[0 for _ in range(N)] for _ in range(N)]
            for i in range(N):
                for j in range(N):
                    for d in dirs:
                        x = i + d[0]
                        y = j + d[1]
                        if x < 0 or x >= N or y < 0 or y >= N: continue
                        newdp[i][j] += dp[x][y]
            dp = newdp
        return sum(map(sum, dp)) / float(8 ** K)
