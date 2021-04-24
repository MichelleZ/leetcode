#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-the-matrix-diagonally/
# Author: Miao Zhang
# Date:   2021-04-24

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        qs = [[] for _ in range(m + n)]
        for i in range(m):
            for j in range(n):
                qs[i - j + n].append(mat[i][j])
        for q in qs:
            q.sort()
        for i in range(m):
            for j in range(n):
                mat[i][j] = qs[i - j + n].pop(0)
        return mat
