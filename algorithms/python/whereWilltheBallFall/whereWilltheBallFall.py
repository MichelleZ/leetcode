#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/where-will-the-ball-fall/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m = len(grid)
        n = len(grid[0])

        def check(j: int) -> int:
            for i in range(m):
                if (grid[i][j] == 1 and (j == n - 1 or grid[i][j + 1] == -1)) or (grid[i][j] == -1 and (j == 0 or grid[i][j - 1] == 1)):
                    return -1
                else:
                    j += grid[i][j]
            return j

        res = [0] * n
        for i in range(n):
            res[i] = check(i)
        return res
