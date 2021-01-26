#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
# Author: Miao Zhang
# Date:   2021-01-26

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        import heapq
        heap = []
        for num in nums:
            heapq.heappush(heap, -1 * num)
        for _ in range(k):
            res = heapq.heappop(heap)
        return -1 * res;
