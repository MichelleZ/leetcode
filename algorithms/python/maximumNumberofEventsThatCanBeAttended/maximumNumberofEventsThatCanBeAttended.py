#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        mind = min(s for s, e in events)
        maxd = max(e for s, e in events)
        seen = [0 for _ in range(maxd - mind + 1)]
        for s, t in sorted(events, key=lambda e: e[1]):
            for i in range(s, t + 1):
                if seen[i - mind]: continue
                seen[i - mind] = 1
                break
        return sum(seen)

class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        events.sort()
        mind = min([s for s, e in events])
        maxd = max([e for s, e in events])
        idx = 0
        heap = []
        res = 0
        for day in range(mind, maxd + 1):
            while idx < len(events) and events[idx][0] == day:
                heapq.heappush(heap, events[idx][1])
                idx += 1
            while heap and heap[0] < day:
                heapq.heappop(heap)
            if heap:
                heapq.heappop(heap)
                res += 1
        return res
