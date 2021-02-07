#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/evaluate-division/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = collections.defaultdict(dict)
        for (a, b), v in zip(equations, values):
            graph[a][b] = v
            graph[b][a] = 1.0 / v
        res = [self.dfs(x, y, graph, set()) if x in graph and y in graph else -1.0 for (x, y) in queries]
        return res
    
    def dfs(self, a: str, b: str, graph: defaultdict, visited: set) -> int:
        if a == b: return 1.0
        visited.add(a)
        for c in graph[a]:
            if c in visited: continue
            #visited.add(c)
            d = self.dfs(c, b, graph, visited)
            if d > 0:
                return d * graph[a][c]
        return -1.0
