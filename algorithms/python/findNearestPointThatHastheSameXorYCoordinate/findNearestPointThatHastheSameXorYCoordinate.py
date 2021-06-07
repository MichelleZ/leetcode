#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
# Author: Miao Zhang
# Date:   2021-06-07

class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        res = float('inf')
        idx = -1
        for i in range(len(points)):
            if points[i][0] == x or points[i][1] == y:
                cur = abs(points[i][0] - x) + abs(points[i][1] - y)
                if cur < res:
                    res = cur
                    idx = i
        return idx
