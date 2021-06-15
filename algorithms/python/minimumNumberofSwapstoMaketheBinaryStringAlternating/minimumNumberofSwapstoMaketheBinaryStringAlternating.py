#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
# Author: Miao Zhang
# Date:   2021-06-15

class Solution:
    def minSwaps(self, s: str) -> int:
        n = len(s)
        n0, n1 = s.count('0'), s.count('1')
        res = float('inf')
        if n1 == (n + 1) // 2 and n0 == n // 2:
            diff1 = 0
            for i in range(n):
                if int(s[i]) == i % 2: 
                    diff1 += 1
            res = min(res, diff1 // 2)
        if n0 == (n + 1) // 2 and n1 == n // 2:
            diff2 = 0
            for i in range(n):
                if int(s[i]) != i % 2:
                    diff2 += 1
            res = min(res, diff2 // 2)
        return -1 if res == float('inf') else res

