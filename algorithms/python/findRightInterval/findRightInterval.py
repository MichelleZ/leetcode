#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-right-interval/
# Author: Miao Zhang
# Date:   2021-02-11

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        import bisect
        itvs = sorted((it[0], i) for i, it in enumerate(intervals))
        res = []
        for itv in intervals:
            idx = bisect.bisect_left(itvs, (itv[1],))
            res.append(itvs[idx][1] if idx < len(intervals) else -1)
        return res
