#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-eaten-apples/
# Author: Miao Zhang
# Date:   2021-05-29

class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        n = len(apples)
        heap = []
        res = 0
        i = 0
        while i < n or heap:
            if i < n and apples[i]:
                heapq.heappush(heap, [i + days[i], i])
            while heap and (heap[0][0] <= i or apples[heap[0][1]] == 0):
                heapq.heappop(heap)
            i += 1
            if not heap: continue
            apples[heap[0][1]] -= 1
            res += 1
        return res
