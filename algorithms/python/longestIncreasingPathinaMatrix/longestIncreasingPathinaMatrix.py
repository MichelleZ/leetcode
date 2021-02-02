#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
# Author: Miao Zhang
# Date:   2021-02-02

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]: return 0
        m = len(matrix)
        n = len(matrix[0])
        res = 0
        dp = [[-1 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                path = self.dfs(matrix, i, j, dp)
                res = max(res, path)
        return res
    
    def dfs(self, matrix: List[List[int]], i: int, j: int, dp: List[List[int]]) -> int:
        if dp[i][j] != -1:
            return dp[i][j]
        res = 1
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for d in dirs:
            x = i + d[0]
            y = j + d[1]
            if x < 0 or x >= len(matrix) or y < 0 or y >= len(matrix[0]) or matrix[x][y] <= matrix[i][j]:
                continue
            path = 1 + self.dfs(matrix, x, y, dp)
            res = max(res, path)
        dp[i][j] = res
        return dp[i][j]
