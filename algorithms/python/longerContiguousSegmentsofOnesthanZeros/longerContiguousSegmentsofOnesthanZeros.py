#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
# Author: Miao Zhang
# Date:   2021-06-15

class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        if not s: return False
        ones, zeros, leno, lenz = 0, 0, 0, 0
        i = 0
        while i < len(s):
            if s[i] == '1':
                zeros = i + 1
                i += 1
                leno = max(leno, i - ones)
            else:
                ones = i + 1
                i += 1
                lenz = max(lenz, i - zeros)
        return True if leno > lenz else False
