#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        kMod = 10 ** 9 + 7
        m = len(pizza)
        n = len(pizza[0])

        calapp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                calapp[i + 1][j + 1] = calapp[i + 1][j] + calapp[i][j + 1] + (pizza[i][j] == 'A') - calapp[i][j]

        def hasApples(x1, y1, x2, y2):
            return (calapp[x2 + 1][y2 + 1] - calapp[x2 + 1][y1] - calapp[x1][y2 + 1] + calapp[x1][y1]) > 0

        cache = [[[-1 for _ in range(k)] for _ in range(n)] for _ in range(m)]

        def dp(x, y, s):
            if s == 0: return hasApples(x, y, m - 1, n - 1)
            if cache[x][y][s] != -1: return cache[x][y][s]
            res = 0
            for i in range(x, m - 1):
                res = (res + hasApples(x, y, i, n - 1) * dp(i + 1, y, s - 1)) % kMod
            for j in range(y, n - 1):
                res = (res + hasApples(x, y, m - 1, j) * dp(x, j + 1, s - 1)) % kMod
            cache[x][y][s] = res
            return res
        return int(dp(0, 0, k - 1))
