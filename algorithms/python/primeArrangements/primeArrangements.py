#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/prime-arrangements/
# Author: Miao Zhang
# Date:   2021-04-15

class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        kMod = 10 ** 9 + 7
        p = 0
        for i in range(1, n + 1):
            p += self.isPrime(i)
        res = 1
        for i in range(1, p + 1):
            res = (res * i) % kMod
        for i in range(1, n - p + 1):
            res = (res * i) % kMod
        return res
    
    def isPrime(self, x: int) -> bool:
        if x < 2: return False
        if x == 2: return True
        for i in range(2, int(x ** 0.5) + 1):
            if x % i == 0:
                return False
        return True
