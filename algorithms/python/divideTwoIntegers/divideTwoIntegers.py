#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/divide-two-integers/
# Author: Miao Zhang
# Date:   2021-01-07

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        flag = (dividend > 0) ^ (divisor > 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        res = 0
        while dividend >= divisor:
            multidivisor, multi = divisor, 1
            while dividend >= multidivisor:
                res += multi
                dividend -= multidivisor
                multi = multi << 1
                multidivisor = multidivisor << 1
        INT_MIN = -(2 **31)
        INT_MAX = 2 **31 - 1
        if flag:
            res *= -1
        
        return res if INT_MIN <= res <= INT_MAX else INT_MAX
