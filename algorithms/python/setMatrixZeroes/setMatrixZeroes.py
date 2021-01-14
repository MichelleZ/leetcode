#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/set-matrix-zeroes/
# Author: Miao Zhang
# Date:   2021-01-14

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        rows = []
        cols = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    rows.append(i)
                    cols.append(j)
        for i in rows:
            matrix[i] = [0] * n
        
        for j in cols:
            for i in range(m):
                matrix[i][j] = 0
