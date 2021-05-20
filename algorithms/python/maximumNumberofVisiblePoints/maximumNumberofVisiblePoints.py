#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-visible-points/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        origin = 0
        tans = []
        for x, y in points:
            if x == location[0] and y == location[1]:
                origin += 1
            else:
                tans.append(math.atan2(y - location[1], x - location[0]))
        tans.sort()
        n = len(tans)
        for i in range(n):
            tans.append(tans[i] + 2.0 * math.pi)
        l, r = 0, 0
        res = 0
        scope = angle * math.pi / 180
        while r < len(tans):
            if tans[r] - tans[l] > scope:
                l += 1
            res = max(res, r - l + 1)
            r += 1
        return res + origin
