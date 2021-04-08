#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-path-in-binary-matrix/
# Author: Miao Zhang
# Date:   2021-04-08

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1: return -1
        n = len(grid)
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        step = 0
        q = collections.deque()
        q.append((0, 0))
        visited = set()
        visited.add((0, 0))
        while q:
            lenq = len(q)
            step += 1
            for _ in range(lenq):
                i, j = q.popleft()
                if i == n - 1 and j == n - 1:
                    return step
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if x < 0 or x >= n or y < 0 or y >= n or grid[x][y] == 1 or (x, y) in visited: continue
                    q.append((x, y))
                    visited.add((x, y))
        return -1
