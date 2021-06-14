#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
# Author: Miao Zhang
# Date:   2021-06-14

class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        g = collections.defaultdict(list)
        indegrees = [0] * n
        for u, v in edges:
            indegrees[v] += 1
            g[u].append(v)
        found = 0
        f = [[0] * 26 for _ in range(n)]
        q = collections.deque()
        for i in range(n):
            if indegrees[i] == 0:
                q.append(i)
        while q:
            found += 1
            u = q.popleft()
            f[u][ord(colors[u]) - ord("a")] += 1
            for v in g[u]:
                indegrees[v] -= 1
                for c in range(26):
                    f[v][c] = max(f[v][c], f[u][c])
                if indegrees[v] == 0:
                    q.append(v)
        if found != n:
            return -1
        
        res = 0
        for i in range(n):
            res = max(res, max(f[i]))
        return res

