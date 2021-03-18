#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/car-fleet/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted([(p, (target - p) / s) for p, s in zip(position, speed)], reverse=True)
        res = 0
        maxt = 0
        for p, t in cars:
            if t > maxt:
                maxt = t
                res += 1
        return res
