#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bricks-falling-when-hit/
# Author: Miao Zhang
# Date:   2021-03-12

class UnionFind:
    def __init__(self, m, n):
        self.root = [i for i in range(m * n + 1)]
        self.rank = [0] * (m * n + 1)
        self.size = [1] * (m * n + 1)
    
    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]
    
    def union(self, x, y):
        parentx, parenty = self.find(x), self.find(y)
        if parentx == parenty: return
        if self.rank[parentx] < self.rank[parenty]:
            parentx, parenty = parenty, parentx
        if self.rank[parentx] == self.rank[parenty]:
            self.rank[parentx] += 1
        self.root[parenty] = parentx
        self.size[parentx] += self.size[parenty]
    
    def top(self):
        fakenode = len(self.size) - 1
        return self.size[self.find(fakenode)] - 1


class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        
        def index(i, j):
            return i * n + j
        
        def neighbors(i, j):
            for x, y in ((i - 1, j), (i + 1, j), (i, j - 1), (i , j + 1)):
                if 0 <= x < m and 0 <= y < n:
                    yield x, y
        
        tmp = [row[:] for row in grid]
        for i, j in hits:
            tmp[i][j] = 0
        
        uf = UnionFind(m, n)
        for i in range(len(tmp)):
            for j in range(len(tmp[0])):
                if tmp[i][j]:
                    idx = index(i, j)
                    if i == 0:
                        uf.union(idx, m * n)
                    if i and tmp[i - 1][j]:
                        uf.union(idx, index(i - 1, j))
                    if j and tmp[i][j - 1]:
                        uf.union(idx, index(i, j - 1))
        
        res = []
        for i, j in reversed(hits):
            pre_roof = uf.top()
            if grid[i][j] == 0:
                res.append(0)
            else:
                idx = index(i, j)
                for x, y in neighbors(i, j):
                    if tmp[x][y]:
                        uf.union(idx, index(x, y))
                if i == 0:
                    uf.union(idx, m * n)
                tmp[i][j] = 1
                res.append(max(0, uf.top() - pre_roof - 1))
        return res[::-1]
