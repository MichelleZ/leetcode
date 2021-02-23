#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/erect-the-fence/
# Author: Miao Zhang
# Date:   2021-02-23

# https://algorithmist.com/wiki/Monotone_chain_convex_hull
#   ---  upper
#  /
# /
# \    /  low
#  ---/
#     p1
#         p2
# p0
# k(p0p1) > k(p2p0)
class Solution:
    def outerTrees(self, points: List[List[int]]) -> List[List[int]]:
        def is_clockwise(
                p0: List[int], p1: List[int], p2: List[int]) -> bool:
            """
            p0, p1, p2 clockwise
            """
            return (p1[1] - p0[1]) * (p2[0] - p0[0]) > \
                (p2[1] - p0[1]) * (p1[0] - p0[0])
        n = len(points)
        points.sort()
        hull = []
        # low part, from left to right, unclockwise
        for x in range(n):
            while len(hull) > 1 and is_clockwise(hull[-2], hull[-1], points[x]):
                hull.pop()
            hull.append(points[x])
        if len(hull) == len(points):
            return hull

        hull.pop()
        for x in range(n - 1, -1, -1):
            while len(hull) > 1 and is_clockwise(hull[-2], hull[-1], points[x]): hull.pop()
            hull.append(points[x])
        hull.pop()
        return hull
