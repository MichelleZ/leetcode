#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
# Author: Miao Zhang
# Date:   2021-02-13

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points: return 0
        points.sort(key=lambda x: x[1])
        cur_pos = points[0][1]
        res = 1
        for i in range(len(points)):
            if cur_pos >= points[i][0]: continue
            cur_pos = points[i][1]
            res += 1
        return res
