#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-average-pass-ratio/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        n = len(classes)
        def ratio(i, delta=0):
            return (classes[i][0] + delta) / (classes[i][1] + delta)
        heap = []
        for i in range(n):
            heapq.heappush(heap, [-ratio(i, 1) + ratio(i), i])
        while extraStudents:
            r, i = heapq.heappop(heap)
            classes[i][0] += 1
            classes[i][1] += 1
            heapq.heappush(heap, [-ratio(i, 1) + ratio(i), i])
            extraStudents -= 1
        res = 0
        for i in range(n):
            res += ratio(i)
        return res / n
