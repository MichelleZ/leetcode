#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
# Author: Miao Zhang
# Date:   2021-05-09

class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        kMod = 10 ** 9 + 7
        horizontalCuts.sort()
        verticalCuts.sort()
        x = max(horizontalCuts[0], h - horizontalCuts[-1])
        y = max(verticalCuts[0], w - verticalCuts[-1])
        for i in range(len(horizontalCuts)):
            x = max(x, horizontalCuts[i] - horizontalCuts[i - 1])
        for j in range(len(verticalCuts)):
            y = max(y, verticalCuts[j] - verticalCuts[j - 1])
        return x * y % kMod
