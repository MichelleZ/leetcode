#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-two-integers/
# Author: Miao Zhang
# Date:   2021-02-04

class Solution:
    def getSum(self, a: int, b: int) -> int:
        while b != 0:
            carry = a & b
            a = (a ^ b) % 0x100000000
            b = (carry << 1) % 0x100000000
        return a if a <= 0x7FFFFFFF else a | (~0x100000000+1)
