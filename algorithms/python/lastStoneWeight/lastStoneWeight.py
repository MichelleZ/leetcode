#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/last-stone-weight/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        import heapq
        stones = list(map(lambda x: -x, stones))
        heapq.heapify(stones)
        while len(stones) > 1:
            x = heapq.heappop(stones)
            y = heapq.heappop(stones)
            if x == y: continue
            heapq.heappush(stones, -abs(x - y))
        return 0 if not stones else -stones[0]
