#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/spiral-matrix-iii/
# Author: Miao Zhang
# Date:   2021-03-21

class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        res = []
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        d = 0 # east
        k = 1
        res.append([r0, c0])
        if len(res) == R * C: return res
        while k:
            for i in range(2):
                for j in range(k):
                    r0 += dirs[d][0]
                    c0 += dirs[d][1]
                    if r0 < 0 or r0 >= R or c0 < 0 or c0 >= C: continue
                    res.append([r0, c0])
                    if len(res) == R * C: return res
                d = (d + 1) % 4;
            k += 1
        return res
