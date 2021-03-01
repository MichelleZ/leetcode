#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/redundant-connection/
# Author: Miao Zhang
# Date:   2021-03-01

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parents = [0] * (len(edges) + 1)
        sizes = [1] * (len(edges) + 1)

        def find(u):
            while parents[u] != u:
                parents[u] = parents[parents[u]]
                u = parents[u]
            return u

        for u, v in edges:
            if parents[u] == 0: parents[u] = u
            if parents[v] == 0: parents[v] = v
            pu, pv = find(u), find(v)
            if pu == pv: return [u, v]
            if sizes[pv] > sizes[pu]:
                pv, pu = pu, pv
            parents[pv] = pu
            sizes[pu] += sizes[pv]
        return []
