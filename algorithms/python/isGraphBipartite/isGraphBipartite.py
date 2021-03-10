#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/is-graph-bipartite/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        colors = [0 for _ in range(n)]
        for i in range(n):
            if colors[i] == 0 and not self.dfs(graph, colors, i, 1): return False
        return True
    
    def dfs(self, graph: List[List[int]], colors: List[int], cur: int, color: int) -> bool:
        colors[cur] = color
        for nxt in graph[cur]:
            if colors[nxt] == color: return False
            if colors[nxt] == 0 and not self.dfs(graph, colors, nxt, -color):
                return False
        return True
