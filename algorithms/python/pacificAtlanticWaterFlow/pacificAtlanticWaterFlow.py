#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/pacific-atlantic-water-flow/
# Author: Miao Zhang
# Date:   2021-02-09

class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix: return []
        m = len(matrix)
        n = len(matrix[0])
        p_visited = [[False for _ in range(n)] for _ in range(m)]
        a_visited = [[False for _ in range(n)] for _ in range(m)]
        for i in range(m):
            # left pacific
            self.dfs(matrix, p_visited, i, 0)
            # right atlantic
            self.dfs(matrix, a_visited, i, n - 1)
        for j in range(n):
            # top pacific
            self.dfs(matrix, p_visited, 0, j)
            # bottom atlantic
            self.dfs(matrix, a_visited, m - 1, j)
        
        res = []
        for i in range(m):
            for j in range(n):
                if p_visited[i][j] and a_visited[i][j]:
                    res.append([i, j])
        return res
    
    def dfs(self, matrix: List[List[int]], visited: List[List[bool]], i: int, j: int) -> None:
        visited[i][j] = True
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for d in dirs:
            x = i + d[0]
            y = j + d[1]
            if x < 0 or x >= len(matrix) or y < 0 or y >= len(matrix[0]) or visited[x][y] or matrix[x][y] < matrix[i][j]:
                continue
            self.dfs(matrix, visited, x, y)
