#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def isPossible(self, target: List[int]) -> bool:
        heap = []
        for t in target:
            heapq.heappush(heap, -t)
        sums = sum(target)
        while True:
            m = -heapq.heappop(heap)
            sums -= m
            if m == 1: return True # largest number is 1
            if sums == 1: return True # [1, m]
            if sums == 0 or sums >= m: return False # [m] or [1,1,1,2]
            m %= sums
            if m == 0: return False
            sums += m
            heapq.heappush(heap, -m)
        return False
