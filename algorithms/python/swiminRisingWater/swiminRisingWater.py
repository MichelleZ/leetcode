#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/swim-in-rising-water/
# Author: Miao Zhang
# Date:   2021-03-09

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        heap = []
        heapq.heappush(heap, (grid[0][0], 0 * n + 0))
        seen = [0 for _ in range(n * n)]
        seen[0] = 1
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while heap:
            node = heapq.heappop(heap)
            t = node[0]
            i = node[1] // n
            j = node[1] % n
            if i == n - 1 and j == n - 1: return t
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if x < 0 or x >= n or y < 0 or y >= n: continue
                if seen[x * n + y]: continue
                seen[x * n + y] = 1
                heapq.heappush(heap, (max(t, grid[x][y]), x * n + y))
        return -1
