#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/path-with-minimum-effort/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        m = len(heights)
        n = len(heights[0])
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def bfs(cost: int) -> bool:
            q = collections.deque()
            seen = [0] * (m * n)
            q.append([0, 0])
            seen[0] = 1
            while q:
                i, j = q.popleft()
                if i == m - 1 and j == n - 1: return True
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if x < 0 or x >= m or y < 0 or y >= n or seen[x * n + y]: continue
                    if abs(heights[x][y] - heights[i][j]) > cost: continue
                    seen[x * n + y] = 1
                    q.append([x, y])
            return False

        l, r = 0, 10 ** 6 + 1
        while l < r:
            mid = l + (r - l) // 2
            if bfs(mid):
                r = mid
            else:
                l = mid + 1
        return l
