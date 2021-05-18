#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/min-cost-to-connect-all-points/
# Author: Miao Zhang
# Date:   2021-05-18

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)

        def dist(p1, p2):
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

        ds = [float(inf)] * n
        for i in range(1, n):
            ds[i] = dist(points[0], points[i])

        res = 0
        for i in range(1, n):
            val = min(ds)
            idx = ds.index(val)
            res += val
            ds[idx] = float('inf')
            for i in range(n):
                if ds[i] == float('inf'):
                    continue
                ds[i] = min(ds[i], dist(points[idx], points[i]))
        return res
