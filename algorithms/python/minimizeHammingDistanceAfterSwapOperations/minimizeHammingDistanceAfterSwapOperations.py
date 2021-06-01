#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
# Author: Miao Zhang
# Date:   2021-06-01

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
            self.p[px] = self.p[py]


class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        uf = UnionFind(n)
        for x, y in allowedSwaps:
            uf.merge(uf.find(x), uf.find(y))
        m = collections.defaultdict(list)
        for i in range(n):
            pi = uf.find(i)
            m[pi].append(i)
        res = 0
        for k, v in m.items():
            a = [source[i] for i in v]
            b = collections.Counter([target[i] for i in v])
            for c in a:
                if b[c] > 0:
                    b[c] -= 1
                else:
                    res += 1
        return res

