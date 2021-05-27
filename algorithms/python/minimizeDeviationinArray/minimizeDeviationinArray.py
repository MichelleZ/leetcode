#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimize-deviation-in-array/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        heap = []
        low = float('inf')
        for num in nums:
            num = num * 2 if num & 1 else num
            heapq.heappush(heap, -num)
            low = min(low, num)
        res = -heap[0] - low
        while heap[0] % 2 == 0:
            x = -heap[0]
            heapq.heappop(heap)
            heapq.heappush(heap, -(x // 2))
            low = min(low, x // 2)
            res = min(res, -heap[0] - low)
        return res
