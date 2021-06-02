#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        n = len(adjacentPairs) + 1
        g = collections.defaultdict(list)
        for u, v in adjacentPairs:
            g[u].append(v)
            g[v].append(u)
        res = [0] * n
        for u, vs in g.items():
            if len(vs) == 1:
                res[0] = u
                res[1] = vs[0]
        for i in range(2, n):
            vs = g[res[i - 1]]
            res[i] = vs[1] if vs[0] == res[i - 2] else vs[0]
        return res
