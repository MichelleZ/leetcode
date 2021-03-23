#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        s = str(n)
        l = len(s)
        res = sum(len(digits) ** i for i in range(1, l))
        for i, c in enumerate(s):
            res += len(digits) ** (l - i - 1) * sum(d < c for d in digits)
            if c not in digits: return res
        return res + 1
