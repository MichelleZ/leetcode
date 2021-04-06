#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-boomerang/
# Author: Miao Zhang
# Date:   2021-04-06

class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        dx0 = points[0][0] - points[1][0]
        dy0 = points[0][1] - points[1][1]
        dx1 = points[0][0] - points[2][0]
        dy1 = points[0][1] - points[2][1]
        return dy0 * dx1 != dy1 * dx0
        
