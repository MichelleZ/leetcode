#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/magic-squares-in-grid/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        for i in range(m - 2):
            for j in range(n - 2):
                res += self.magic(grid, i, j)
        return res
    
    def magic(self, grid: List[List[int]], x: int, y: int) -> bool:
        cnt = [0 for _ in range(10)]
        rows = [0] * 3
        cols = [0] * 3
        corrects = [15] * 3
        dia = 0
        for i in range(3):
            for j in range(3):
                val = grid[x + i][y + j]
                if val < 0 or val > 9: return False
                cnt[val] += 1
                if cnt[val] > 1: return False
                rows[i] += val
                cols[j] += val
                if i == j: dia += val
        return rows == corrects and cols == corrects and dia == 15
