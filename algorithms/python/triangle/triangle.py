#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/triangle/
# Author: Miao Zhang
# Date:   2021-01-19

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m = len(triangle)
        for i in range(m):
            for j in range(i + 1):
                if i == 0 and j == 0: continue
                if j == 0: triangle[i][j] += triangle[i - 1][j]
                elif (j == i): triangle[i][j] += triangle[i - 1][j - 1]
                else: triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1])
        return min(triangle[m - 1])
