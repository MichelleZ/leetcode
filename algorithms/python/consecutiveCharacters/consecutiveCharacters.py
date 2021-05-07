#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/consecutive-characters/
# Author: Miao Zhang
# Date:   2021-05-07

class Solution:
    def maxPower(self, s: str) -> int:
        last = '?'
        cur = 0
        res = 0
        for c in s:
            if last != c:
                cur = 0
                last = c
            cur += 1
            res = max(res, cur)
        return res
