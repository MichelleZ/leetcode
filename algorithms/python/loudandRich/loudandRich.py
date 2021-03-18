#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/loud-and-rich/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        graph = [[] for _ in range(n)]
        for u, v in richer:
            graph[v].append(u)
        res = [None] * n

        def dfs(i):
            if res[i] != None: return
            res[i] = i
            for j in graph[i]:
                dfs(j)
                if quiet[res[j]] < quiet[res[i]]:
                    res[i] = res[j]

        for i in range(n):
            dfs(i)
        return res
