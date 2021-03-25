#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
# Author: Miao Zhang
# Date:   2021-03-24

class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        right = 0
        left = 0
        for c in S:
            left += 1 if c == '(' else -1
            if left == -1:
                right += 1
                left += 1
        return left + right
