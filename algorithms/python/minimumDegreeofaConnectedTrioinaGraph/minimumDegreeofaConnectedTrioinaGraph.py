#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        indegree = [0 for _ in range(n)]
        g = [[0 for _ in range(n)] for _ in range(n)]
        for u, v in edges:
            g[u - 1][v - 1] = 1
            g[v - 1][u - 1] = 1
            indegree[u - 1] += 1
            indegree[v - 1] += 1
        res = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if g[i][j] and g[i][k]  and g[j][k]:
                        res = min(res, indegree[i] + indegree[j] + indegree[k] - 6)
        return -1 if res == float('inf') else res
