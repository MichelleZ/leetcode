#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-string-with-swaps/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        ss = list(s)
        n = len(s)
        g = [[] for _ in range(n)]
        for u, v in pairs:
            g[u].append(v)
            g[v].append(u)
        
        seen = set()
        idx = []
        t = []
        
        def dfs(i):
            if i in seen: return
            seen.add(i)
            idx.append(i)
            t.append(s[i])
            for nxt in g[i]:
                dfs(nxt)
        
        for i in range(n):
            if i in seen: continue
            idx.clear()
            t.clear()
            dfs(i)
            idx.sort()
            t.sort()
            for k in range(len(idx)):
                ss[idx[k]] = t[k]
        
        return ''.join(ss)
            
