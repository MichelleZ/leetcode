#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cat-and-mouse/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        n = len(graph)
        dp = [[[-1 for _ in range(n)] for _ in range(n)] for _ in range(2 * n)]
        res = self.search(graph, 0, 1, 2, dp)
        return res

    def search(self, graph: List[List[int]], t: int, x: int, y: int, dp: List[List[List[int]]]) -> int:
        if t == len(graph) * 2: return 0
        if x == y:
            dp[t][x][y] = 2
            return 2
        if x == 0:
            dp[t][x][y] = 1
            return 1
        if dp[t][x][y] != -1:
            return dp[t][x][y]
        if t % 2 == 0: # mouse
            if any(self.search(graph, t+1, x_nxt, y, dp)==1 for x_nxt in graph[x]):
                dp[t][x][y] = 1
                return 1
            if any(self.search(graph, t+1, x_nxt, y, dp)==0 for x_nxt in graph[x]):
                dp[t][x][y] = 0
                return 0
            dp[t][x][y] = 2
            return 2
        else: # cat
            if any(self.search(graph, t+1, x, y_nxt, dp)==2 for y_nxt in graph[y] if y_nxt != 0):
                dp[t][x][y] = 2
                return 2
            if any(self.search(graph, t+1, x, y_nxt, dp)==0 for y_nxt in graph[y] if y_nxt != 0):
                dp[t][x][y] = 0
                return 0
            dp[t][x][y] = 1
            return 1
