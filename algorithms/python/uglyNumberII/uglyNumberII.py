#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ugly-number-ii/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        res = [1]
        i2 = 0
        i3 = 0
        i5 = 0
        while len(res) < n:
            next2 = res[i2] * 2
            next3 = res[i3] * 3
            next5 = res[i5] * 5
            nxt = min(next2, next3, next5)
            if nxt == next2: i2 += 1
            if nxt == next3: i3 += 1
            if nxt == next5: i5 += 1
            res.append(nxt)
        return res[-1]
