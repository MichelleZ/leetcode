#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/coloring-a-border/
# Author: Miao Zhang
# Date:   2021-04-05

class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        visited=set([(r0,c0)])
        edge=set()
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        def dfs(i, j):
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if 0 <= x < m and 0 <= y < n and grid[x][y] == grid[r0][c0]:
                    if (x, y) not in visited:
                        visited.add((x,y))
                        dfs(x, y)
                else:
                    edge.add((i, j))

        dfs(r0,c0)
        for x, y in edge:
            grid[x][y]=color
        return grid
