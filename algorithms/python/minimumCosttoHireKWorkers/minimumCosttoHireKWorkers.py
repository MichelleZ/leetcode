#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        from fractions import Fraction
        workers = sorted((Fraction(w, q), q, w)
                         for q, w in zip(quality, wage))
        print(workers)
        res = float('inf')
        pool = []
        sumq = 0
        for ratio, q, w in workers:
            heapq.heappush(pool, -q)
            sumq += q
            if len(pool) > K:
                sumq += heapq.heappop(pool)
            if len(pool) == K:
                res = min(res, ratio * sumq)
        return float(res)
        
