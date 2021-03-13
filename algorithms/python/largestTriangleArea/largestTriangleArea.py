#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-triangle-area/
# Author: Miao Zhang
# Date:   2021-03-13

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        res = 0
        n = len(points)
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    (x1, y1), (x2, y2), (x3, y3) = points[i], points[j], points[k]
                    res = max(res, 0.5 * abs(x1 *(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)))
        return res
