#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
# Author: Miao Zhang
# Date:   2021-06-17

class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        diff = [0] * 52
        for s, e in ranges:
            diff[s] += 1
            diff[e + 1] -= 1
        cur = 0
        for i in range(1, 51):
            cur += diff[i]
            if i >= left and i <= right and cur <= 0:
                return False
        return True
