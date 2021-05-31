#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def checkWays(self, pairs: List[List[int]]) -> int:
        m = collections.defaultdict(set)
        for u, v in pairs:
            m[u] |= set((u, v))
            m[v] |= set((u, v))
        if not any(len(m[e]) == len(m) for e in m):
            return 0
        multiple = 0
        for u, v in pairs:
            alls = m[u] | m[v]
            r0 = int(m[u] == alls)
            r1 = int(m[v] == alls)
            if r0 + r1 == 0: return 0
            multiple |= r0 * r1
        return 1 + multiple
