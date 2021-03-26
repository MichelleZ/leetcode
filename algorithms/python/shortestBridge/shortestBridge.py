#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-bridge/
# Author: Miao Zhang
# Date:   2021-03-26

class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        n = len(A)
        q = collections.deque()
        
        def dfs(i, j):
            A[i][j] = -1
            q.append((i, j))
            for x, y in [(i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)]:
                if 0 <= x < n and 0 <= y < n and A[x][y] == 1:
                    dfs(x, y)
        
        def find_first_land():
            for i in range(n):
                for j in range(n):
                    if A[i][j]:
                        dfs(i, j)
                        return
        
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        find_first_land()
        step = 0
        while q:
            lenq = len(q)
            for _ in range(lenq):
                i, j = q.popleft()
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if 0 <= x < n and 0 <= y < n:
                        if A[x][y] == 1: return step
                        if A[x][y] == 0:
                            A[x][y] = -1
                            q.append((x, y))
            step += 1
        return step
                
