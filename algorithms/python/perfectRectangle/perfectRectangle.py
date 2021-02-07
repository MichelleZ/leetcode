#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/perfect-rectangle/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        left = float('inf')
        right = float('-inf')
        top = float('-inf')
        bottom = float('inf')
        corners = set()
        area = 0
        for rec in rectangles:
            p1 = (rec[0], rec[1])
            p2 = (rec[2], rec[1])
            p3 = (rec[2], rec[3])
            p4 = (rec[0], rec[3])
            area += (p3[0] - p1[0]) * (p3[1] - p1[1])
            for p in [p1, p2, p3, p4]:
                if p in corners:
                    corners.remove(p)
                else:
                    corners.add(p)
        if len(corners) != 4: return False
        corlist = list(corners)
        corlist.sort(key = lambda x: (x[0], x[1]))
        return area == (corlist[-1][0] - corlist[0][0]) * (corlist[-1][1] - corlist[0][1])
