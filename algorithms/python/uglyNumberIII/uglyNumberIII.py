#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ugly-number-iii/
# Author: Miao Zhang
# Date:   2021-04-17

class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        ab = math.lcm(a, b)
        ac = math.lcm(a, c)
        bc = math.lcm(b, c)
        abc = math.lcm(a, bc)
        l = 1
        r = (10 ** 9) * 2
        while l < r:
            m = l + (r - l) // 2
            k = m // a + m // b + m // c - m // ab - m // ac - m // bc + m // abc
            if k >= n:
                r = m
            else:
                l = m + 1
        return l
