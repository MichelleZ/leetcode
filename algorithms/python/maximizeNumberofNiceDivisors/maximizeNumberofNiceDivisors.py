#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximize-number-of-nice-divisors/
# Author: Miao Zhang
# Date:   2021-06-09

class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        kMod = 10 ** 9 + 7
        def power(base, exp):
            nonlocal kMod
            res = 1
            while exp:
                if exp & 1:
                    res = (res * base) % kMod
                base = (base * base) % kMod
                exp >>= 1
            return res
        if primeFactors <= 3: return primeFactors
        if primeFactors % 3 == 0:
            return power(3, primeFactors // 3)
        elif primeFactors % 3 == 1:
            return (power(3, primeFactors // 3 - 1) * 4) % kMod
        else:
            return (power(3, primeFactors // 3) * 2) % kMod
        return -1
