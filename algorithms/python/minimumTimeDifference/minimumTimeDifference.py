#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-time-difference/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def convert(time):
            return int(time[:2]) * 60 + int(time[3:])
        timePoints = list(map(convert, timePoints))
        timePoints.sort()
        return min((y - x) % (24 * 60)  for x, y in zip(timePoints, timePoints[1:] + timePoints[:1]))
