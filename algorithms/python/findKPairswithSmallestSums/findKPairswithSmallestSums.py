#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
# Author: Miao Zhang
# Date:   2021-02-05

import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        res = []
        heap = []
        for i in range(min(len(nums1), k)):
            for j in range(min(len(nums2), k)):
                if len(heap) < k:
                    heapq.heappush(heap, (-nums1[i] - nums2[j], nums1[i], nums2[j]))
                elif -nums1[i] - nums2[j] > heap[0][0]:
                    heapq.heapreplace(heap, (-nums1[i] - nums2[j], nums1[i], nums2[j]))
        while len(heap) > 0:
            _, a, b = heapq.heappop(heap)
            res.append([a, b])
        return res
