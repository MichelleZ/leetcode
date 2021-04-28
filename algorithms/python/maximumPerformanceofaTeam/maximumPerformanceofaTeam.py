#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-performance-of-a-team/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        es = [[] for _ in range(n)]
        for i in range(n):
            es[i] += [efficiency[i], speed[i]]
        es.sort(reverse=True)
        heap = []
        sums = 0
        res = 0
        for i in range(n):
            if i >= k:
                sums -= heapq.heappop(heap)
            sums += es[i][1]
            heapq.heappush(heap, es[i][1])
            res = max(res, sums * es[i][0])
        return res % (10 ** 9 + 7)
