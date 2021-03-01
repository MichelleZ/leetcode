#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/redundant-connection-ii/
# Author: Miao Zhang
# Date:   2021-03-01

class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        parents = [0] * (len(edges) + 1)
        roots = [0] * (len(edges) + 1)
        sizes = [1] * (len(edges) + 1)
        
        def find(u: int) -> int:
            while u != roots[u]:
                roots[u] = roots[roots[u]]
                u = roots[u]
            return u
        
        ans1 = []
        ans2 = []
        for edge in edges:
            u = edge[0]
            v = edge[1]
            if parents[v] > 0:
                ans1 = [parents[v], v]
                ans2 = [u, v]
                edge[0] = edge[1] = -1
            parents[v] = u
        
        for u, v in edges:
            if u < 0 or v < 0: continue
            if not roots[u]: roots[u] = u
            if not roots[v]: roots[v] = v
            pu = find(u)
            pv = find(v)
            if pu == pv:
                return ans1 if len(ans1) else [u, v]
            if sizes[pv] > sizes[pu]:
                pv, pu = pu, pv
            roots[pv] = pu
            sizes[pu] += sizes[pv]
        
        return ans2
            
