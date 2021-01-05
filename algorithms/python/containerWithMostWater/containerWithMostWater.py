#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/container-with-most-water/
# Author: Miao Zhang
# Date:   2021-01-05

class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxarea = 0
        l = 0
        r = len(height) - 1
        while l < r:
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return maxarea
