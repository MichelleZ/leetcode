#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-width-ramp/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        res = 0
        m = float('inf')
        for i in sorted(range(len(A)), key=A.__getitem__):
            res = max(res, i - m)
            m = min(i, m)
        return res
