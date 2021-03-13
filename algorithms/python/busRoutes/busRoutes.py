#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/bus-routes/
# Author: Miao Zhang
# Date:   2021-03-13

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target: return 0
        # bus stop: ith bus travel
        graph = collections.defaultdict(list)
        for i in range(len(routes)):
            for stop in routes[i]:
                graph[stop].append(i)
        visited = [0] * len(routes)
        q = deque()
        q.append(source)
        res = 0
        while q:
            n = len(q)
            res += 1
            for _ in range(n):
                stop = q.popleft()
                for travel in graph[stop]:
                    if visited[travel]: continue
                    visited[travel] = 1
                    for s in routes[travel]:
                        if s == target: return res
                        q.append(s)
        return -1
        
