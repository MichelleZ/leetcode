#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/detect-cycles-in-2d-grid/
# Author: Miao Zhang
# Date:   2021-05-15

class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        seen = [[0 for _ in range(n)] for _ in range(m)]
        
        def dfs(i, j, pi, pj):
            seen[i][j] += 1
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n: continue
                if grid[x][y] != grid[i][j]: continue
                if seen[x][y] and x != pi and y != pj: return True
                if not seen[x][y] and dfs(x, y, i, j): return True
            return False
        
        for i in range(m):
            for j in range(n):
                if not seen[i][j] and dfs(i, j, -1, -1):
                    return True
        return False
