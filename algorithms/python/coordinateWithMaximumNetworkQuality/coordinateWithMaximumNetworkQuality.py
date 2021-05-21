#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/coordinate-with-maximum-network-quality/
# Author: Miao Zhang
# Date:   2021-05-21

class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        n = 50
        res = [0, 0]
        maxsignal = 0
        for x1 in range(51):
            for y1 in range(51):
                s = 0
                for [x2, y2, q] in towers:
                    d = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
                    if d <= radius:
                        s += floor(q / (d + 1))
                if s > maxsignal:
                    maxsignal = s
                    res = [x1, y1]
        return res
