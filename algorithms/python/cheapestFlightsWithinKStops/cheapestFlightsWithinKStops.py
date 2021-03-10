#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/cheapest-flights-within-k-stops/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        kInfCost = 1e9
        cost = [kInfCost for _ in range(n)]
        cost[src] = 0
        for i in range(K + 1):
            tmp = list(cost)
            for p in flights:
                tmp[p[1]] = min(tmp[p[1]], cost[p[0]] + p[2])
            cost = tmp
        return -1 if cost[dst] >= 1e9 else cost[dst]
