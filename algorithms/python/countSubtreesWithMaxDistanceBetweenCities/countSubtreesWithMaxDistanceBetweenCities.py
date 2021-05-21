#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/submissions/
# Author: Miao Zhang
# Date:   2021-05-21

class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u - 1].append(v - 1)
            g[v - 1].append(u - 1)
        q = collections.deque()

        def bfs(start, visited):
            q.append(start)
            visited[start] = 1
            count = 0
            dist = -1
            while q:
                qlen = len(q)
                for _ in range(qlen):
                    u = q.popleft()
                    count += 1
                    for v in g[u]:
                        if visited[v] == 0:
                            q.append(v)
                dist += 1
            return [dist, count]

        res = [0] * (n - 1)
        for s in range(1 << n):
            if bin(s).count('1') <= 1: continue
            seen = [-1] * n
            for i in range(n):
                if s & (1 << i):
                    seen[i] = 0
            tmp = s & (s - 1)
            start = -1
            while tmp:
                start += 1
                tmp >>= 1
            dis, cnt = bfs(start, seen)
            if cnt != bin(s).count('1'): continue
            res[dis - 1] += 1
        return res
