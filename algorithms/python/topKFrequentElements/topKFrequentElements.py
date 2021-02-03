#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/top-k-frequent-elements/
# Author: Miao Zhang
# Date:   2021-02-03

from collections import defaultdict
from heapq import *
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = defaultdict(int)
        for n in nums:
            count[n] += 1
        heap = []
        for i, v in count.items():
            heappush(heap, (v, i));
            if len(heap) > k: 
                heappop(heap)
        res = [heappop(heap)[1] for _ in range(len(heap))]
        return res
