#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x: (x[0], x[1]))
        res = 0
        for i in range(1, len(points)):
            res = max(res, points[i][0] - points[i - 1][0])
        return res
