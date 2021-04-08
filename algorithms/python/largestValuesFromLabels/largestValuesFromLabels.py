#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-values-from-labels/
# Author: Miao Zhang
# Date:   2021-04-08

class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        heap = []
        for x in zip(values, labels):
            heapq.heappush(heap, [-x[0], x[1]])
        res = 0
        cnt = collections.defaultdict(int)
        while num_wanted > 0 and heap:
            value, label = heapq.heappop(heap)
            value = -value
            cnt[label] += 1
            if cnt[label] <= use_limit:
                res += value
                num_wanted -= 1
        return res

