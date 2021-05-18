#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
# Author: Miao Zhang
# Date:   2021-05-18

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        rows = [0] * m
        cols = [0] * n
        for i in range(m):
            for j in range(n):
                rows[i] += mat[i][j]
                cols[j] += mat[i][j]
        res = 0
        for i in range(m):
            for j in range(n):
                res += mat[i][j] and rows[i] == 1 and cols[j] == 1
        return res
