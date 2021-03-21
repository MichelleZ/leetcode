#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/nth-magical-number/
# Author: Miao Zhang
# Date:   2021-03-21

class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        kMod = 10 ** 9 + 7
        l = 2
        r = 1e15

        def gcd(a, b):
            if a % b == 0: return b
            return gcd(b, a % b)

        d = gcd(a, b)
        while l < r:
            m = l + (r - l) // 2
            if m // a + m // b - m // (a * b // d) < n:
                l = m + 1
            else:
                r = m
        return int(l) % kMod
