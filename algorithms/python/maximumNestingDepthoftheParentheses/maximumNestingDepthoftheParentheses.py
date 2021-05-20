#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def maxDepth(self, s: str) -> int:
        cnt = 0
        res = 0
        for c in s:
            if c == '(':
                cnt += 1
            elif c == ')':
                cnt -= 1
            res = max(res, cnt)
        return res
