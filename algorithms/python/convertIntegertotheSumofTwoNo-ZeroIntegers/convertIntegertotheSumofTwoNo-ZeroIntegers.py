#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        if n == 0:
            return [-1, 1]
        a = 1
        b = n - a
        while True:
            if '0' not in str(a) and '0' not in str(b):
                return [a, b]
            else:
                a += 1
                b -= 1
