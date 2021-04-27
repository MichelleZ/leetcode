#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
# Author: Miao Zhang
# Date:   2021-04-27

# enqueue order: appendleft or append
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        # left right low up
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        q = collections.deque()
        seen = [0 for _ in range(m * n)]
        q.append((0 * n + 0, 0))
        while q:
            cur, cost = q.popleft()
            i = cur // n
            j = cur % n
            if i == m - 1 and j == n - 1: 
                return cost
            if seen[i * n + j]: continue
            seen[i * n + j] += 1
            for k in range(len(dirs)):
                x = i + dirs[k][0]
                y = j + dirs[k][1]
                if x < 0 or x >= m or y < 0 or y >= n or seen[x * n + y]:
                    continue
                if grid[i][j] == k + 1:
                    q.appendleft((x * n + y, cost))
                else:
                    q.append((x * n + y, cost + 1))
        return -1
