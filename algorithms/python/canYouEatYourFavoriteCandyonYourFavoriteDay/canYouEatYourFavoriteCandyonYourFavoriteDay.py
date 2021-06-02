#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
# Author: Miao Zhang
# Date:   2021-06-02

class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        sums = [0] * (len(candiesCount) + 1)
        for i in range(len(candiesCount)):
            sums[i + 1] = sums[i] + candiesCount[i]
        res = []
        for typ, day, cap in queries:
            x1 = day + 1
            y1 = (day + 1) * cap
            x2 = sums[typ] + 1
            y2 = sums[typ + 1]
            res.append(not (x1 > y2 or y1 < x2))
        return res
