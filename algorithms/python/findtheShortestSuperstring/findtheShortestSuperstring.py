#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-shortest-superstring/
# Author: Miao Zhang
# Date:   2021-03-27

class Solution:
    def shortestSuperstring(self, words: List[str]) -> str:
        n = len(words)
        
        overlaps = [[0] * n for _ in range(n)]
        for i, x in enumerate(words):
            for j, y in enumerate(words):
                if i != j:
                    for k in range(min(len(x), len(y)), -1, -1):
                        if x.endswith(y[:k]):
                            overlaps[i][j] = k
                            break
        
        # dp[mask][i]: end with i-th element
        dp= [[0] * n for _ in range(1 << n)]
        parent = [[None] * n for _ in range(1 << n)]
        for mask in range(1, 1 << n):
            for bit in range(n):
                if (mask >> bit) & 1:
                    pmask = mask ^ (1 << bit)
                    if pmask == 0: continue
                    for i in range(n):
                        if (pmask >> i) & 1:
                            value = dp[pmask][i] + overlaps[i][bit]
                            if value > dp[mask][bit]:
                                dp[mask][bit] = value
                                parent[mask][bit] = i
        
        perm = []
        mask = (1 << n) - 1
        i = max(range(n), key = dp[-1].__getitem__)
        while i is not None:
            perm.append(i)
            mask, i = mask ^ (1 << i), parent[mask][i]
        
        perm = perm[::-1]
        seen = [False] * n
        for x in perm:
            seen[x] = True
        perm.extend([i for i in range(n) if not seen[i]])
        
        res = [words[perm[0]]]
        for i in range(1, len(perm)):
            overlap = overlaps[perm[i - 1]][perm[i]]
            res.append(words[perm[i]][overlap:])
        
        return ''.join(res)                            
