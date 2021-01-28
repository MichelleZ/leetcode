#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-of-digit-one/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def countDigitOne(self, n: int) -> int:
        cnt = 0;
        i = 1;
        while i <= n:
            a = n // i
            b = n % i
            if a % 10 == 0: cnt += a // 10 * i
            elif a % 10 == 1: cnt += a // 10 * i + (b + 1)
            else: cnt += (a // 10 + 1) * i
            i *= 10
        return cnt
