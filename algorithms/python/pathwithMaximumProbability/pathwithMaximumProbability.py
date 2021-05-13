#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/path-with-maximum-probability/
# Author: Miao Zhang
# Date:   2021-05-13

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        g = [[] for _ in range(n)]
        for i, e in enumerate(edges):
            g[e[0]].append([e[1], -math.log(succProb[i])])
            g[e[1]].append([e[0], -math.log(succProb[i])])
        seen = [0] * n
        dist = [float('inf')] * n
        dist[start] = 0.0
        q = [[0.0, start]]
        while q:
            _, cur = heapq.heappop(q)
            seen[cur] = 1
            if cur == end: return math.exp(-dist[cur])
            for nxt, w in g[cur]:
                if seen[nxt] or dist[cur] + w > dist[nxt]:
                    continue
                dist[nxt] = dist[cur] + w
                heapq.heappush(q, (dist[nxt], nxt))
        return 0
