#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/trapping-rain-water-ii/
# Author: Miao Zhang
# Date:   2021-02-08

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not heightMap: return 0
        m = len(heightMap)
        n = len(heightMap[0])
        heap = []
        visited = [[False for _ in range(n)] for _ in range(m)]
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heapq.heappush(heap, [heightMap[i][j], i, j])
                    visited[i][j] = True
        res = 0
        max_height = float('-inf')
        while heap:
            height, i, j = heapq.heappop(heap)
            max_height = max(max_height, height)
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if 0 <= x < m and 0 <= y < n and not visited[x][y]:
                    visited[x][y] = True
                    if heightMap[x][y] < max_height:
                        res += max_height - heightMap[x][y]
                    heapq.heappush(heap, [heightMap[x][y], x, y])
        return res
