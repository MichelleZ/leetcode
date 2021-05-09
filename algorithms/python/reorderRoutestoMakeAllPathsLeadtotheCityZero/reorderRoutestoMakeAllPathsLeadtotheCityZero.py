#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
# Author: Miao Zhang
# Date:   2021-05-09

class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for u, v in connections:
            g[u].append([v, 1])
            g[v].append([u, 0])
        q = collections.deque()
        q.append(0)
        seen = [0 for _ in range(n)]
        res = 0
        while q:
            cur = q.popleft()
            seen[cur] = 1
            for nxt, cost in g[cur]:
                if seen[nxt]: continue
                res += cost
                q.append(nxt)
        return res
