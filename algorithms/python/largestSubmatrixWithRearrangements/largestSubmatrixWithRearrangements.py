#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-submatrix-with-rearrangements/
# Author: Miao Zhang
# Date:   2021-06-01

class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        for i in range(1, m):
            for j in range(n):
                if matrix[i][j]:
                    matrix[i][j] += matrix[i - 1][j]
        res = 0
        for i in range(m):
            matrix[i].sort(reverse=True)
            for j in range(n):
                res = max(res, (j + 1) * matrix[i][j])
        return res
