#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
# Author: Miao Zhang
# Date:   2021-03-08

class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19]
        return sum(bin(x).count('1') in primes
                   for x in range(L, R + 1))
