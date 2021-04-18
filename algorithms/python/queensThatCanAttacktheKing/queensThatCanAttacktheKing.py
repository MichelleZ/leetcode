#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/queens-that-can-attack-the-king/
# Author: Miao Zhang
# Date:   2021-04-18

class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        grid = [[0 for _ in range(8)] for _ in range(8)]
        for qx, qy in queens:
            grid[qx][qy] = 1
        res = []
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        for d in dirs:
            x = king[0] + d[0]
            y = king[1] + d[1]
            while x >= 0 and x < 8 and y >= 0 and y < 8:
                if grid[x][y] == 1:
                    res.append([x, y])
                    break
                x += d[0]
                y += d[1]
        return res
