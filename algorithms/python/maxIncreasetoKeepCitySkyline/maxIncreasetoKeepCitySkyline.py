#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
# Author: Miao Zhang
# Date:   2021-03-12

class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        rows = [0] * m
        cols = [0] * n
        for i in range(m):
            for j in range(n):
                rows[i] = max(rows[i], grid[i][j])
                cols[j] = max(cols[j], grid[i][j])
        res = 0
        for i in range(m):
            for j in range(n):
                res += min(rows[i], cols[j]) - grid[i][j]
        return res
