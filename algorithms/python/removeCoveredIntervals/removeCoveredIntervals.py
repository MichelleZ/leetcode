#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-covered-intervals/
# Author: Miao Zhang
# Date:   2021-04-21

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        res = 0
        prev = 0
        for _, end in intervals:
            if end > prev:
                res += 1
                prev = end
        return res
