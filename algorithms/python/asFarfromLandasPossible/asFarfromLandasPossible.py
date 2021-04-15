#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/as-far-from-land-as-possible/
# Author: Miao Zhang
# Date:   2021-04-15

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        res = -1
        q = collections.deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    q.append((i, j))
        steps = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                i, j = q.popleft()
                if grid[i][j] == 2:
                    res = max(res, steps)
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] != 0: continue
                    grid[x][y] = 2
                    q.append((x, y))
            steps += 1
        return res
        
