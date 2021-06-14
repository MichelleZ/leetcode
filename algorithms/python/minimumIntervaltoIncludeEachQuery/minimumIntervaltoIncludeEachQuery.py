#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-interval-to-include-each-query/
# Author: Miao Zhang
# Date:   2021-06-14

class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        n = len(intervals)
        m = len(queries)
        intervals.sort(key=lambda x: -x[1])
        qs = []
        for i in range(m):
            qs.append([queries[i], i])
        qs.sort(reverse=True)
        res = [0 for _ in range(m)]
        j = 0
        heap = [] # {size, -left}
        for query, i in qs:
            while j < n and intervals[j][1] >= query:
                heapq.heappush(heap, [intervals[j][1] - intervals[j][0] + 1, -intervals[j][0]])
                j += 1
            while heap and -heap[0][1] > query:
                heapq.heappop(heap)
            res[i] = -1 if not heap else heap[0][0]
        return res
