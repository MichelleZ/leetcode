#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/merge-intervals/
# Author: Miao Zhang
# Date:   2021-01-12

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort(key = lambda x: x[0])
        start = intervals[0][0]
        end = intervals[0][1]
        for it in intervals:
            if it[0] <= end:
                end = max(end, it[1])
            else:
                res.append([start, end])
                start = it[0]
                end = it[1]
        res.append([start, end])
        return res
