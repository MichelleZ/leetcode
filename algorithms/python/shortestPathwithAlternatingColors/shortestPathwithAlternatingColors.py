#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-path-with-alternating-colors/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        edgesr = [set() for _ in range(n)]
        edgesb = [set() for _ in range(n)]
        for s, e in red_edges:
            edgesr[s].add(e)
        for s, e in blue_edges:
            edgesb[s].add(e)
        seenr = set()
        seenb = set()
        res = [-1] * n
        q = collections.deque()
        # red is 0, blue is 1
        q.append((0, 0)) # pre is red, nxt is blue
        q.append((0, 1)) # pre is blue, nxt is red
        seenr.add(0)
        seenb.add(0)
        steps = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                node, isred = q.popleft()
                res[node] = min(res[node], steps) if res[node] >= 0 else steps
                edges = edgesr if isred else edgesb
                seen = seenr if isred else seenb
                for nxt in edges[node]:
                    if nxt in seen: continue
                    seen.add(nxt)
                    q.append((nxt, 1 - isred))
            steps += 1
        return res
