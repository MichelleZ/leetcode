#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/height-checker/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        h = sorted(heights)
        res = 0
        for i in range(len(heights)):
            res += (heights[i] != h[i])
        return res
