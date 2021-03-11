#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/
# Author: Miao Zhang
# Date:   2021-03-11

class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        return self.g(K) - self.g(K - 1)
    
    def g(self, K: int) -> int:
        l = 0
        r = sys.maxsize
        while l < r:
            m = l + (r - l) // 2
            zeros = self.numZeros(m)
            if zeros <= K: l = m + 1
            else: r = m
        return l
    
    def numZeros(self, n: int) -> int:
        if n < 5: return 0
        return n // 5 + self.numZeros(n // 5)
