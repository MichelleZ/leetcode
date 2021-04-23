#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        nums = [0 for _ in range(len(ranges))]
        for i in range(n + 1):
            s = max(0, i - ranges[i])
            nums[s] = i + ranges[i]
        res = 0
        lastend = 0
        end = 0
        for i in range(n + 1):
            if i > end: return -1
            if i > lastend:
                lastend = end
                res += 1
            end = max(end, nums[i])
        return res
