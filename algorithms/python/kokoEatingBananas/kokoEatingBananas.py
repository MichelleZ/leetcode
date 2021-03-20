#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/koko-eating-bananas/
# Author: Miao Zhang
# Date:   2021-03-20

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        while l < r:
            m = l + (r - l) // 2
            ho = 0
            for p in piles:
                ho += (p + m - 1) // m
            if ho <= h:
                r = m
            else:
                l = m + 1
        return l
