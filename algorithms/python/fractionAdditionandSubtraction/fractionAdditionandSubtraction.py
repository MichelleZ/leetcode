#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/fraction-addition-and-subtraction/
# Author: Miao Zhang
# Date:   2021-02-24

class Solution:
    def fractionAddition(self, expression: str) -> str:
        nums = list(map(int, re.findall('[+-]?[0-9]+', expression)))
        a = 0
        b = 1
        for c, d in zip(nums[::2], nums[1::2]):
            a = a * d + b * c
            b *= d
            g = math.gcd(a, b)
            a //= g
            b //= g
        return str(a) + '/' + str(b)
