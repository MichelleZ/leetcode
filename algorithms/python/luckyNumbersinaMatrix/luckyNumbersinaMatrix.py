#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        rows = [float('inf')] * m
        cols = [float('-inf')] * n
        for i in range(m):
            for j in range(n):
                rows[i] = min(rows[i], matrix[i][j])
                cols[j] = max(cols[j], matrix[i][j])
        res = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == rows[i] and matrix[i][j] == cols[j]:
                    res.append(matrix[i][j])
        return res
