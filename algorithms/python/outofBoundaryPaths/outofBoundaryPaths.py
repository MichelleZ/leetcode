#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/out-of-boundary-paths/
# Author: Miao Zhang
# Date:   2021-02-23

class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        kMod = 10 ** 9 + 7
        dp = [[0 for _ in range(n)] for _ in range(m)]
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for s in range(1, N + 1):
            tmp = [[0 for _ in range(n)] for _ in range(m)]
            for x in range(m):
                for y in range(n):
                    for d in dirs:
                        dx = x + d[0]
                        dy = y + d[1]
                        if dx < 0 or dx >= m or dy < 0 or dy >= n:
                            tmp[x][y] += 1
                        else:
                            tmp[x][y] = (tmp[x][y] + dp[dx][dy]) % kMod
            dp = tmp
        return dp[i][j]
