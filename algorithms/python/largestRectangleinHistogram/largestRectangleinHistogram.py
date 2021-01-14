#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-rectangle-in-histogram/
# Author: Miao Zhang
# Date:   2021-01-14

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        res = 0
        heights.append(0)
        for i in range(len(heights)):
            if not stack or heights[i] >= heights[stack[-1]]:
                stack.append(i)
            else:
                while stack and heights[i] < heights[stack[-1]]:
                    h = heights[stack[-1]]
                    stack.pop()
                    w = i if not stack else i - stack[-1] - 1
                    res = max(res, h * w)
                stack.append(i)
        return res
