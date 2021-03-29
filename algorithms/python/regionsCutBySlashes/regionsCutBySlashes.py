#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/regions-cut-by-slashes/
# Author: Miao Zhang
# Date:   2021-03-29

class DSU:
    def __init__(self, n):
        self.root = [i for i in range(n)]
        self.size = n

    def find(self, x):
        if self.root[x] != x:
            self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px != py:
            self.root[px] = py
            self.size -= 1


class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid)
        dsu = DSU(4 * n * n)
        for i in range(n):
            for j in range(n):
                idx = 4 * (i * n + j)
                if grid[i][j] == '/':
                    dsu.union(idx + 0, idx + 3)
                    dsu.union(idx + 1, idx + 2)
                elif grid[i][j] == '\\':
                    dsu.union(idx + 0, idx + 1)
                    dsu.union(idx + 2, idx + 3)
                else:
                    dsu.union(idx + 0, idx + 1)
                    dsu.union(idx + 1, idx + 2)
                    dsu.union(idx + 2, idx + 3)
                if i + 1 < n:
                    dsu.union(idx + 2, idx + 4 * n + 0)
                if j + 1 < n:
                    dsu.union(idx + 1, idx + 4 + 3)
        return dsu.size
