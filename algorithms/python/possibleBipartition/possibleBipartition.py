#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/possible-bipartition/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        self.graph = [[] for _ in range(N)]
        for d in dislikes:
            self.graph[d[0] - 1].append(d[1] - 1)
            self.graph[d[1] - 1].append(d[0] - 1)
        self.colors = [0 for _ in range(N)]
        for i in range(N):
            if self.colors[i] == 0 and not self.dfs(i, 1): return False
        return True
    
    def dfs(self, cur: int, color: int) -> bool:
        self.colors[cur] = color
        for nxt in self.graph[cur]:
            if self.colors[nxt] == color: return False
            if self.colors[nxt] == 0 and not self.dfs(nxt, -color): return False
        return True

class Solution(object):
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        graph = [[] for _ in range(N)]
        for d in dislikes:
            graph[d[0] - 1].append(d[1] - 1)
            graph[d[1] - 1].append(d[0] - 1)
        colors = [0 for _ in range(N)]
        q = collections.deque()
        for i in range(N):
            if colors[i] != 0: continue
            q.append(i)
            colors[i] = 1
            while q:
                cur = q.popleft()
                for nxt in graph[cur]:
                    if colors[nxt] == colors[cur]: return False
                    if colors[nxt] != 0: continue
                    colors[nxt] = -colors[cur]
                    q.append(nxt)
        return True
