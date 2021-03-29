#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-area-rectangle-ii/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        EPS = 1e-7
        points = set(map(tuple, points))

        res = float('inf')
        for p1, p2, p3 in itertools.permutations(points, 3):
            p4 = p2[0] + p3[0] - p1[0], p2[1] + p3[1] - p1[1]
            if p4 in points:
                v21 = complex(p2[0] - p1[0], p2[1] - p1[1])
                v31 = complex(p3[0] - p1[0], p3[1] - p1[1])
                if abs(v21.real * v31.real + v21.imag * v31.imag) < EPS:
                    area = abs(v21) * abs(v31)
                    res = min(res, area)

        return res if res < float('inf') else 0
