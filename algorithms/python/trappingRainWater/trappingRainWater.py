#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/trapping-rain-water/
# Author: Miao Zhang
# Date:   2021-01-08

# Monotonic stack
class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        stack = []
        for i in range(len(height)):
            while stack and stack[-1][0] < height[i]:
                cur = stack.pop()
                while stack and cur[0] == stack[-1][0]:
                    stack.pop()
                if stack:
                    res += (min(stack[-1][0], height[i]) - cur[0]) * (i - stack[-1][1] - 1)
            stack.append([height[i], i])
        return res
