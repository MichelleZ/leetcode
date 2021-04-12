#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        res = []
        d = 0
        for c in seq:
            if c == '(':
                d += 1
                res.append(d % 2)
            if c == ')':
                res.append(d % 2)
                d -= 1
        return res
