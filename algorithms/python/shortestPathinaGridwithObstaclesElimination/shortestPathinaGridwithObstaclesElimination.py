#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        seen = [float('inf') for _ in range(m * n)]
        q = collections.deque()
        q.append((0, 0, 0))
        seen[0 * n + 0] = 0
        steps = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                i, j, val = q.popleft()
                if i == m - 1 and j == n - 1:
                    return steps
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if x < 0 or x >= m or y < 0 or y >= n:
                        continue
                    v = val + grid[x][y]
                    if v >= seen[x * n + y] or v > k:
                        continue
                    seen[x * n + y] = v
                    q.append((x, y, v))
            steps += 1
        return -1
