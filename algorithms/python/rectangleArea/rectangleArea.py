#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rectangle-area/
# Author: Miao Zhang
# Date:   2021-01-27

class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        points = [((A, B), (C, D)), ((E, F), (G, H))]
        points.sort()
        ((A, B), (C, D)), ((E, F), (G, H)) = points
        area1 = (D - B) * (C - A)
        area2 = (H - F) * (G - E)
        x, y = min(C, G) - max(A, E), min(D, H) - max(B, F)
        area = 0
        if x > 0 and y > 0:
            area = x * y
        return area1 + area2 - area
