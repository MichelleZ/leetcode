#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
# Author: Miao Zhang
# Date:   2021-06-01

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        res = 0
        cur = 0
        for r1, r2 in rectangles:
            if min(r1, r2) > cur:
                cur = min(r1, r2)
                res = 0
            if min(r1, r2) == cur:
                res += 1
        return res
