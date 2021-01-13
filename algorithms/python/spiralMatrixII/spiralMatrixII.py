#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/spiral-matrix-ii/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 for _ in range(n)] for _ in range(n)]
        i, j = 0, 0
        di, dj = 0, 1
        for num in range(1, n * n + 1):
            res[i][j] = num
            if res[(i + di) % n][(j + dj) % n] != 0:
                di, dj = dj, -di
            i += di
            j += dj
        return res
