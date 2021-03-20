#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-refueling-stops/
# Author: Miao Zhang
# Date:   2021-03-20

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        cur = startFuel
        res = 0
        heap = []
        i = 0
        while True:
            if cur >= target: return res
            while i < len(stations) and stations[i][0] <= cur:
                heapq.heappush(heap, -stations[i][1])
                i += 1
            if not heap: break
            cur += (-heapq.heappop(heap))
            res += 1
        return -1
