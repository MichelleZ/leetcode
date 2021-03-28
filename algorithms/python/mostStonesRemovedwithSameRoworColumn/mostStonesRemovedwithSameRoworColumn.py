#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
# Author: Miao Zhang
# Date:   2021-03-28

class UnionFind:
    def __init__(self, n):
        self.root = [i for i in range(n)]
    
    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)
        self.root[px] = py
    
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        uf = UnionFind(20000)
        for i, j in stones:
            uf.union(i, j + 10000)
        
        return n - len({uf.find(x) for x, y in stones})
