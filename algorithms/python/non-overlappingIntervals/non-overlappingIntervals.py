#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/non-overlapping-intervals/
# Author: Miao Zhang
# Date:   2021-02-11

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals: return 0
        intervals.sort(key=lambda x: x[0])
        res = 0
        last = 0
        for i in range(1, len(intervals)):
            if intervals[last][1] > intervals[i][0]:
                if intervals[i][1] < intervals[last][1]:
                    last = i
                res += 1
            else:
                last = i
        return res
