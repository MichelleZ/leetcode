#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/integer-break/
# Author: Miao Zhang
# Date:   2021-02-03

class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2: return 1
        if n == 3: return 2
        res = 1
        while n > 4:
            res *= 3
            n -= 3
        return res * n
