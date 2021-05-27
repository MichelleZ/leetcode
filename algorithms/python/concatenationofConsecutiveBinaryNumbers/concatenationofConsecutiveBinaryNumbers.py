#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
# Author: Miao Zhang
# Date:   2021-05-27

class Solution:
    def concatenatedBinary(self, n: int) -> int:
        kMod = 10 ** 9 + 7
        shift = 0
        res = 0
        for i in range(1, n + 1):
            if (i & (i - 1)) == 0:
                shift += 1
            res = ((res << shift) + i) % kMod
        return res
