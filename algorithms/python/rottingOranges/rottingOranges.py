#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rotting-oranges/
# Author: Miao Zhang
# Date:   2021-03-31

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        fresh = 0
        q = collections.deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1: fresh += 1
                if grid[i][j] == 2: q.append((i, j))
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        days = 0
        while q and fresh:
            qlen = len(q)
            for _ in range(qlen):
                i, j = q.popleft()
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] != 1:
                        continue
                    fresh -= 1
                    grid[x][y] = 2
                    q.append((x, y))
            
            days += 1
        return -1 if fresh else days
