#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        p = [i for i in range(n)]
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]
        for u, v in connections:
            p[find(u)] = find(v)
        s = set()
        for i in range(n):
            s.add(find(i))
        return len(s) - 1
