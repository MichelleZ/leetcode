#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-it-is-a-straight-line/
# Author: Miao Zhang
# Date:   2021-04-18

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n = len(coordinates)
        x1 = coordinates[0][0]
        y1 = coordinates[0][1]
        dx = coordinates[1][0] - x1
        dy = coordinates[1][1] - y1
        for i in range(2, n):
            tx = coordinates[i][0] - x1
            ty = coordinates[i][1] - y1
            if tx * dy - ty * dx:
                return False
        return True
