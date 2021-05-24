#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rank-transform-of-a-matrix/
# Author: Miao Zhang
# Date:   2021-05-24

class UnionFind:
    def __init__(self, n):
        self.p = [i for i in range(n)]

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
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        rank = [0] * (m + n)
        dic = collections.defaultdict(list)
        for i in range(m):
            for j in range(n):
                dic[matrix[i][j]].append([i, j])
        for k in sorted(dic):
            uf = UnionFind(m + n)
            rank2 = rank[:]
            for i, j in dic[k]:
                i, j = uf.find(i), uf.find(j + m)
                uf.merge(i, j)
                rank2[j] = max(rank2[i], rank2[j])
            for i, j in dic[k]:
                rank[i] = rank[j + m] = matrix[i][j] = rank2[uf.find(i)] + 1
        return matrix

