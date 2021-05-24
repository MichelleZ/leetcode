#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        m = {}
        res = -1
        for i, c in enumerate(s):
            if c not in m:
                m[c] = i
            else:
                res = max(res, i - m[c] - 1)
        return res
