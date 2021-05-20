#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximal-network-rank/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        degrees = [0] * n
        connected = set()
        for u, v in roads:
            degrees[u] += 1
            degrees[v] += 1
            connected.add((u << 16) | v)
            connected.add((v << 16) | u)
        res = 0
        for i in range(n):
            for j in range(i + 1, n):
                res = max(res, degrees[i] + degrees[j] -
                               (1 if ((i << 16) | j) in connected else 0))
        return res
