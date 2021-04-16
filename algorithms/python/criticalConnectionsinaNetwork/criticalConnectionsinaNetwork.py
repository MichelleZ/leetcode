#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/critical-connections-in-a-network/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        g = collections.defaultdict(set)
        for u, v in connections:
            g[u].add(v)
            g[v].add(u)
        
        low = [-1] * n
        res = []
        
        def dfs(v: int, par: int, lvl: int) -> int:
            '''
            starting for v, explore all the node connecting it, return the minimum val
            '''
            low[v] = lvl + 1
            for child in g[v]:
                if child == par:
                    continue
                elif low[child] == -1:
                    low[v] = min(low[v], dfs(child, v, lvl + 1))
                else:
                    low[v] = min(low[v], low[child])
            
            if low[v] == lvl + 1 and v != 0:
                res.append([par, v])
            return low[v]
        
        dfs(0, -1, 0)
        return res
