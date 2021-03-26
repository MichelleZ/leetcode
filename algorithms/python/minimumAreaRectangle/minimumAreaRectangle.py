#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-area-rectangle/
# Author: Miao Zhang
# Date:   2021-03-27

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        dic = collections.defaultdict(set)
        for point in points:
            dic[point[0]].add(point[1])
        n = len(points)
        min_area = float('inf')
        for i in range(n):
            for j in range(i + 1, n):
                x0 = points[i][0]
                y0 = points[i][1]
                x1 = points[j][0]
                y1 = points[j][1]
                if x0 == x1 or y0 == y1: continue
                area = abs(x0 - x1) * abs(y0 - y1)
                if area > min_area: continue
                if y0 not in dic[x1] or y1 not in dic[x0]:
                    continue
                min_area = area
        return 0 if min_area == float('inf') else min_area
