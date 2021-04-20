#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-time-visiting-all-points/
# Author: Miao Zhang
# Date:   2021-04-20

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        res = 0
        for i in range(1, len(points)):
            dx = abs(points[i][0] - points[i - 1][0])
            dy = abs(points[i][1] - points[i - 1][1])
            res += min(dx, dy) + abs(dx - dy)
        return res
