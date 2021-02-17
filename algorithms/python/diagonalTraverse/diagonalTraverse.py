#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/diagonal-traverse/
# Author: Miao Zhang
# Date:   2021-02-17

class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0: return []
        m = len(matrix)
        n = len(matrix[0])
        res = []
        dirs = [(-1, 1), (1, -1)]
        i = 0
        j = 0
        k = 0
        for _ in range(m * n):
            res.append(matrix[i][j])
            i += dirs[k][0]
            j += dirs[k][1]
            if i >= m:
                i = m - 1
                j += 2
                k = 1 - k
            if j >= n:
                j = n - 1
                i += 2
                k = 1 - k
            if i < 0:
                i = 0
                k = 1 - k
            if j < 0:
                j = 0
                k = 1 - k
        return res
