#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/angle-between-hands-of-a-clock/
# Author: Miao Zhang
# Date:   2021-04-25

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        min_angle = minutes * 360 / 60
        hour_angle = (hour + minutes / 60) * 360 / 12
        return min(abs(min_angle - hour_angle), 360 - abs(min_angle - hour_angle))
