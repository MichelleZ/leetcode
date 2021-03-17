#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/shortest-path-visiting-all-nodes/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        finalstate = (1 << n) - 1
        visited = [[0 for _ in range(1 << n)] for _ in range(n)]
        q = collections.deque()
        for i in range(n):
            q.append((i, 1 << i))
        step = 0
        while q:
            lenq = len(q)
            for _ in range(lenq):
                node, state = q.popleft()
                if state == finalstate: return step
                if visited[node][state]: continue
                visited[node][state] = 1
                for nxt in graph[node]:
                    q.append((nxt, state | (1 << nxt)))
            step += 1
        return -1
        
