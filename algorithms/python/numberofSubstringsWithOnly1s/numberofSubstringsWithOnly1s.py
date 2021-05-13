#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-substrings-with-only-1s/
# Author: Miao Zhang
# Date:   2021-05-12

class Solution:
    def numSub(self, s: str) -> int:
        kMod = 10 ** 9 + 7
        res = 0
        cur = 0
        for c in s:
            cur = cur + 1 if c == '1' else 0
            res += cur
        return res % kMod
