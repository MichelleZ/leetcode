#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/01-matrix/
# Author: Miao Zhang
# Date:   2021-02-21

class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        q = deque()
        visited = [[0 for _ in range(n)] for _ in range(m)]
        res = [[float('inf') for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    visited[i][j] = 1
                    q.append([i, j])
        val = 0
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while q:
            qlen = len(q)
            for _ in range(qlen):
                i, j = q.popleft()
                res[i][j] = val
                for d in dirs:
                    x = i + d[0]
                    y = j + d[1]
                    if 0 <= x < m and 0 <= y < n and visited[x][y] == 0:
                        visited[x][y] = 1
                        q.append([x, y])
            val += 1
        return res

