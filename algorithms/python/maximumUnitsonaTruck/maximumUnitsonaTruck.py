#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-units-on-a-truck/
# Author: Miao Zhang
# Date:   2021-05-31

class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        res = 0
        for b in boxTypes:
            res += b[1] * min(b[0], truckSize)
            truckSize -= b[0]
            if truckSize <= 0: break
        return res
