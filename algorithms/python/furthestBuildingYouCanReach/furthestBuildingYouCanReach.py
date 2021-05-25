#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/furthest-building-you-can-reach/
# Author: Miao Zhang
# Date:   2021-05-25

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        n = len(heights)
        heap = []
        for i in range(1, n):
            d = heights[i] - heights[i - 1]
            if d <= 0: continue
            heapq.heappush(heap, d)
            if len(heap) <= ladders: continue
            bricks -= heap[0]
            heapq.heappop(heap)
            if bricks < 0:
                return i - 1
        return n - 1
