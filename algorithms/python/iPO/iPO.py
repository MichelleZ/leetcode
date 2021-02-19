#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ipo/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        import heapq
        heap = []
        capital = []
        for i in range(len(Profits)):
            if Profits[i] <= 0: continue
            if Capital[i] <= W:
                heapq.heappush(heap, -Profits[i])
            else:
                capital.append([Capital[i], Profits[i]])
        capital.sort(key=lambda x: x[0])
        while heap and k > 0:
            W += -heapq.heappop(heap)
            while capital and capital[0][0] <= W:
                heapq.heappush(heap, -capital[0][1])
                capital.pop(0)
            k -= 1
        return W
