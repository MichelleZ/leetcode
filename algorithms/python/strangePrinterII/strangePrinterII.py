#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/strange-printer-ii/
# Author: Miao Zhang
# Date:   2021-05-19

class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        maxc = 60
        m = len(targetGrid)
        n = len(targetGrid[0])
        insides = [set() for _ in range(maxc + 1)]
        for c in range(1, maxc + 1):
            l, r, t, b = n, -1, m, -1
            for i in range(m):
                for j in range(n):
                    if targetGrid[i][j] == c:
                        l, r, t, b = min(l, j), max(r, j), min(t, i), max(b, i)
            if l == -1: continue
            for i in range(t, b + 1):
                for j in range(l, r + 1):
                    if targetGrid[i][j] != c:
                        insides[c].add(targetGrid[i][j])
        seen = [0] * (maxc + 1)
        
        def hasCycle(c):
            if seen[c] == 1: return True
            if seen[c] == 2: return False
            seen[c] = 1
            for c2 in insides[c]:
                if hasCycle(c2): return True
            seen[c] = 2
            return False
        
        for c in range(1, maxc + 1):
            if hasCycle(c): return False
        return True
