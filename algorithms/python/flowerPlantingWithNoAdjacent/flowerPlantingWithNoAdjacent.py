#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/flower-planting-with-no-adjacent/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        res = [0] * n
        graph = [list() for i in range(n)]
        for p in paths:
            graph[p[0] - 1].append(p[1] - 1)
            graph[p[1] - 1].append(p[0] - 1)
        for i in range(n):
            mask = 0
            for j in graph[i]:
                mask |= (1 << res[j])
            for c in range(1, 5):
                if not (mask & (1 << c)) and res[i] == 0:
                    res[i] = c
        return res
