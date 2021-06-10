#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        res = []
        for x0, y0, r in queries:
            rs = r * r
            cnt = 0
            for x, y in points:
                if (x - x0) * (x - x0) + (y - y0) * (y - y0) <= rs:
                    cnt += 1
            res.append(cnt)
        return res

