#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/circle-and-rectangle-overlapping/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        dx = x_center - max(x1, min(x2, x_center))
        dy = y_center - max(y1, min(y2, y_center))
        return dx * dx + dy * dy <= radius * radius
