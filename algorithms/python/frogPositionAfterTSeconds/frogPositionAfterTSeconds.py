#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/frog-position-after-t-seconds/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        g = [[] for _ in range(n + 1)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        p = [0] * (n + 1)
        p[1] = 1.0
        q = collections.deque([1])
        seen = [0] * (n + 1)
        seen[1] = 1
        for _ in range(t):
            qlen = len(q)
            for _ in range(qlen):
                cur = q.popleft()
                children = 0
                for nxt in g[cur]:
                    if not seen[nxt]:
                        children += 1
                for nxt in g[cur]:
                    if not seen[nxt]:
                        seen[nxt] = 1
                        q.append(nxt)
                        p[nxt] = p[cur] / children
                if children > 0: p[cur] = 0.0
        return p[target]
