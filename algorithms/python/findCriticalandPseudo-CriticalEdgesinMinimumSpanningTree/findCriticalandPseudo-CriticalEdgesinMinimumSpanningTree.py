#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
# Author: Miao Zhang
# Date:   2021-05-10

class UnionFind:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n
    
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def Union(self, x: int, y: int) -> bool:
        px = self.find(x)
        py = self.find(y)
        if px == py: return False
        if self.rank[px] == self.rank[py]:
            self.parent[px] = py
            self.rank[py] += 1
        elif self.rank[px] > self.rank[py]:
            self.parent[py] = px
        else:
            self.parent[px] = py
        return True

    
class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        for i in range(len(edges)):
            edges[i].append(i)
        edges.sort(key=lambda x: x[2])
        
        def MST(ex=-1, inc=-1):
            uf = UnionFind(n)
            cost = 0
            cnt = 0
            if inc >= 0:
                cost += edges[inc][2]
                uf.Union(edges[inc][0], edges[inc][1])
                cnt += 1
            for i in range(len(edges)):
                if i == ex: continue
                if not uf.Union(edges[i][0], edges[i][1]):
                    continue
                cost += edges[i][2]
                cnt += 1
            return cost if cnt == n - 1 else float('inf')
        
        mincost = MST()
        criticals = []
        pseudos = []
        for i in range(len(edges)):
            if MST(i) > mincost:
                criticals.append(edges[i][3])
            elif MST(-1, i) == mincost:
                pseudos.append(edges[i][3])
        return [criticals, pseudos]
