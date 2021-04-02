#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        l = max(weights)
        r = sum(weights) + 1
        while l < r:
            m = l + (r - l) // 2
            d = 1
            t = 0
            for w in weights:
                t += w
                if t > m:
                    t = w
                    d += 1
            if d > D:
                l = m + 1
            else:
                r = m
        return l
