#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-integers-by-the-power-value/
# Author: Miao Zhang
# Date:   2021-04-28

class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        vals = []
        for i in range(lo, hi + 1):
            p = 0
            x = i
            while x != 1:
                if x & 1:
                    x = x * 3 + 1
                else:
                    x //= 2
                p += 1
            vals.append([p, i])
        vals.sort()
        return vals[k - 1][1]
