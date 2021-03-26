#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-falling-path-sum/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        while len(matrix) >= 2:
            row = matrix.pop()
            for j in range(len(row)):
                matrix[-1][j] += min(row[max(0, j - 1): min(len(row), j + 2)])
        return min(matrix[0])
