#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/max-points-on-a-line/
# Author: Miao Zhang
# Date:   2021-01-22

from collections import defaultdict
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        res = 0
        for i in range(n):
            count = defaultdict()
            same_points = 1
            max_points = 0
            for j in range(i + 1, n):
                if points[i][0] == points[j][0] and points[i][1] == points[j][1]:
                    same_points += 1
                else:
                    dx = points[j][0] - points[i][0] 
                    dy = points[j][1] - points[i][1] 
                    if dx == 0: 
                        if 'inf' not in count:
                            count['inf'] = 1
                        else:
                            count['inf'] += 1
                        k = 'inf'
                    else:
                        k = 1.0 * dy / dx
                        if k not in count:
                            count[k] = 1
                        else:
                            count[k] += 1
                    max_points = max(max_points, count[k])
            res = max(res, max_points + same_points)
        return res
