#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/graph-connectivity-with-threshold/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        if threshold == 0:
            return [True] * len(queries)
        p = list(range(n + 1))
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]
        for x in range(threshold + 1, n + 1):
            if p[x] == x:
                for y in range(2 * x, n + 1, x):
                    p[max(find(x), find(y))] = min(find(x), find(y))
        return [find(x) == find(y) for x, y in queries]
