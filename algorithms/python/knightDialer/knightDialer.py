#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/knight-dialer/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def knightDialer(self, n: int) -> int:
        kMod = 10 ** 9 + 7
        dirs = [[-2, -1], [-2, 1], [-1, -2], [-1, 2], [1, -2], [1, 2], [2, -1], [2, 1]]
        dp = [[1 for _ in range(3)] for _ in range(4)]
        dp[3][0] = 0
        dp[3][2] = 0
        for k in range(1, n):
            tmp = [[0 for _ in range(3)] for _ in range(4)]
            for i in range(4):
                for j in range(3):
                    if i == 3 and j != 1: continue
                    for d in dirs:
                        x = i + d[0]
                        y = j + d[1]
                        if x < 0 or x >= 4 or y < 0 or y >= 3: continue
                        tmp[i][j] = (tmp[i][j] + dp[x][y]) % kMod;
            dp = tmp
        res = 0
        for i in range(4):
            for j in range(3):
                res = (res + dp[i][j]) % kMod;
        return res
