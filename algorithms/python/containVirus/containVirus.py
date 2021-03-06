#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/contain-virus/
# Author: Miao Zhang
# Date:   2021-03-06

class Solution:
    def containVirus(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        
        def neighbors(i, j):
            dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if 0 <= x < m and 0 <= y < n:
                    yield x, y
        
        def dfs(i, j):
            if (i, j) not in visited:
                visited.add((i, j))
                regions[-1].add((i, j))
                for x, y in neighbors(i, j):
                    if grid[x][y] == 1:
                        dfs(x, y)
                    elif grid[x][y] == 0:
                        frontiers[-1].add((x, y))
                        walls[-1] += 1
        
        res = 0
        while True:
            visited = set()
            regions = [] #  Virus infected area
            frontiers = [] # Virus free zone
            walls = []
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1 and (i, j) not in visited:
                        regions.append(set())
                        frontiers.append(set())
                        walls.append(0)
                        dfs(i, j)
            if not regions: break
            
            target_idx = frontiers.index(max(frontiers, key=len))
            res += walls[target_idx]
            for i, region in enumerate(regions):
                if i == target_idx:
                    for r, c in region:
                        grid[r][c] = 2 # protected by wall
                else:
                    for r, c in region:
                        for nx, ny in neighbors(r, c):
                            if grid[nx][ny] == 0:
                                grid[nx][ny] = 1
        
        return res
