#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
# Author: Miao Zhang
# Date:   2021-05-18

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.edges = 0

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def merge(self, x: int, y: int) -> int:
        px, py = self.find(x), self.find(y)
        if px == py: return 1
        self.parent[px] = py
        self.edges += 1
        return 0


class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        a, b = UnionFind(n + 1), UnionFind(n + 1)
        res = 0
        for t, u, v in edges:
            if t != 3: continue
            res += a.merge(u, v)
            b.merge(u, v)
        for t, u, v in edges:
            if t == 3: continue
            uf = a if t == 1 else b
            res += uf.merge(u, v)
        return res if (a.edges == n - 1 and b.edges == n - 1) else -1

