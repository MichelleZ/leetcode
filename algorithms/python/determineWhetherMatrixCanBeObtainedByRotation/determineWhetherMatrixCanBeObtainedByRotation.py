#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        m = len(mat)
        n = len(mat[0])
        for k in range(4):
            tmp = [[0 for _ in range(m)] for _ in range(n)]
            for i in range(m):
                for j in range(n):
                    tmp[j][m - 1 - i] = mat[i][j]
            if tmp == target: return True
            mat = tmp[:]
        return False
