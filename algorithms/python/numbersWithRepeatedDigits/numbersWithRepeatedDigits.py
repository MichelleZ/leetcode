#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/numbers-with-repeated-digits/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        
        def A(m, n):
            if n == 0: 
                return 1
            return A(m, n - 1) * (m - n + 1)
        
        digits = []
        x = N + 1
        while x > 0:
            digits.insert(0, x % 10)
            x //= 10
        res = 0
        dlen = len(digits)
        for i in range(1, dlen):
            res += 9 * A(9, i - 1)
        visited = set()
        for i in range(dlen):
            if i > 0:
                j = 0
            else:
                j = 1
            while j < digits[i]:
                if j not in visited:
                    res += A(9 - i, dlen - i - 1)
                j += 1
            if digits[i] in visited: break
            visited.add(digits[i])
        return N - res
