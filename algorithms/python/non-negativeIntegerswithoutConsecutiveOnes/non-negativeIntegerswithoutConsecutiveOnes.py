#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def findIntegers(self, num: int) -> int:
        res = 0
        k = 31
        pre = 0
        f = [0] * 32
        f[0] = 1
        f[1] = 2
        for i in range(2, 32):
            f[i] = f[i - 1] + f[i - 2]
        while k >= 0:
            if num & (1 << k):
                res += f[k]
                if pre: return res
                pre = 1
            else:
                pre = 0
            k -= 1
        return res + 1
