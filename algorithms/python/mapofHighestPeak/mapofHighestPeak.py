#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/map-of-highest-peak/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m = len(isWater)
        n = len(isWater[0])
        res = [[-1 for _ in range(n)] for _ in range(m)]
        q = collections.deque()
        for i in range(m):
            for j in range(n):
                if isWater[i][j]:
                    q.append([i, j])
                    res[i][j] = 0
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while q:
            i, j = q.popleft()
            for d in dirs:
                x = i + d[0]
                y = j + d[1]
                if x < 0 or x >= m or y < 0 or y >= n: continue
                if res[x][y] != -1: continue
                res[x][y] = res[i][j] + 1
                q.append([x, y])
        return res
