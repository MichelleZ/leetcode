#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
# Author: Miao Zhang
# Date:   2021-05-28

class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
    
    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]
    
    def merge(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px != py:
            self.p[px] = py
            
    
class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        m = len(queries)
        for i in range(m):
            queries[i].append(i)
        edgeList.sort(key=lambda x: x[2])
        queries.sort(key=lambda x: x[2])
        res = [False] * m
        i = 0
        uf = UnionFind(n)
        for q in queries:
            while i < len(edgeList) and edgeList[i][2] < q[2]:
                uf.merge(uf.find(edgeList[i][0]), uf.find(edgeList[i][1]))
                i += 1
            res[q[3]] = uf.find(q[0]) == uf.find(q[1])
        return res
        
