#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        matrix = [[0 for _ in range(n)] for _ in range(m)]
        for indice in indices:
            for j in range(n):
                matrix[indice[0]][j] += 1
            for i in range(m):
                matrix[i][indice[1]] += 1
        res = 0
        for i in range(m):
            for j in range(n):
                res += matrix[i][j] & 1
        return res
