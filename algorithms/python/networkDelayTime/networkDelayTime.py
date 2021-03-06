#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/network-delay-time/
# Author: Miao Zhang
# Date:   2021-03-06

# dfs
class Solution(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((w, v))
        dist = {node: float('inf') for node in range(1, n + 1)}
        
        def dfs(node, time):
            if time >= dist[node]: return
            dist[node] = time
            for t, v in sorted(graph[node]):
                dfs(v, t + time)
        
        dfs(k, 0)
        res = max(dist.values())
        return res if res < float('inf') else -1

# Dijkstra #
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))
        
        dist = {node: float('inf') for node in range(1, n + 1)}
        visited = [False] * (n + 1)
        dist[k] = 0
        
        while True:
            cand_node = -1
            cand_dist = float('inf')
            for i in range(1, n + 1):
                if not visited[i] and dist[i] < cand_dist:
                    cand_dist = dist[i]
                    cand_node = i
            
            if cand_node < 0: break
            visited[cand_node] = True
            for v, w in graph[cand_node]:
                dist[v] = min(dist[v], dist[cand_node] + w)
        
        res = max(dist.values())
        return res if res < float('inf') else -1
