#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        seen = [0] * n
        
        def dfs(cur):
            seen[cur] = 1
            res = 0
            for nxt in g[cur]:
                if seen[nxt]: continue
                cost = dfs(nxt)
                if cost > 0 or hasApple[nxt]:
                    res += 2 + cost
            return res
        
        return dfs(0)
