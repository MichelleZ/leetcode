#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximal-rectangle/
# Author: Miao Zhang
# Date:   2021-01-14

# refer 84
# enhanced version
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        heights = [0] * (len(matrix[0]) + 1)
        res = 0
        
        for row in matrix:
            for j in range(len(matrix[0])):
                # must heights[j] + 1 
                heights[j] = heights[j] + 1 if row[j] == '1' else 0
            stack = []
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
