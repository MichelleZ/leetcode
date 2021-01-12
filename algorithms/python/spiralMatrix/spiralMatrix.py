#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/spiral-matrix/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        if len(matrix) == 0:
            return res
        i, j = 0, 0
        di, dj = 0, 1
        for _ in range(len(matrix) * len(matrix[0])):
            res.append(matrix[i][j])
            matrix[i][j] = 0
            if matrix[(i + di) % len(matrix)][(j + dj) % len(matrix[0])] == 0:
                di, dj = dj, -di
            i += di
            j += dj
        return res
