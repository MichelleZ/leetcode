#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-pairs-of-nodes/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def countPairs(self, n: int, edges: List[List[int]], queries: List[int]) -> List[int]:
        nodedegrees = [0] * n
        edgefreq = collections.defaultdict(int)
        for u, v in edges:
            u, v = min(u, v) - 1, max(u, v) - 1
            nodedegrees[u] += 1
            nodedegrees[v] += 1
            edgefreq[(u << 16) | v] += 1
        maxdegree = max(nodedegrees)
        degreecnt = collections.defaultdict(int)
        for i in range(n):
            degreecnt[nodedegrees[i]] += 1
        cnts = [0] * (maxdegree * 2 + 2)
        for d1, c1 in degreecnt.items():
            for d2, c2 in degreecnt.items():
                if d1 < d2: cnts[d1 + d2] += c1 * c2;
                elif d1 == d2: cnts[d1 * 2] += c1 * (c1 - 1) // 2
        for k, freq in edgefreq.items():
            u = k >> 16
            v = k & 0xFFFF
            cnts[nodedegrees[u] + nodedegrees[v]] -= 1
            cnts[nodedegrees[u] + nodedegrees[v] - freq] += 1
        for i in range(len(cnts) - 2, -1, -1):
            cnts[i] += cnts[i + 1]
        res = []
        for q in queries:
            res.append(cnts[min(q + 1, len(cnts) - 1)])
        return res
