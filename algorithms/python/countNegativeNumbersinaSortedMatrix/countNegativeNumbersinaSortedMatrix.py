#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        i = 0
        j = n - 1
        while i < m and j >= 0:
            if grid[i][j] < 0:
                res += m - i
                j -= 1
            else:
                i += 1
        return res
