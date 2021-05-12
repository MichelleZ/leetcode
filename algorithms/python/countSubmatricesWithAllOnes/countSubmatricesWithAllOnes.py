#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-submatrices-with-all-ones/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m = len(mat)
        n = len(mat[0])
        
        def subMat(x, y):
            maxn = n
            cnt = 0
            for i in range(x, m):
                j = y
                while j < maxn:
                    if mat[i][j]:
                        cnt += 1
                    else:
                        maxn = j
                    j += 1
            return cnt
        
        res = 0
        for x in range(m):
            for y in range(n):
                res += subMat(x, y)
        return res
