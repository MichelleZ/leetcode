#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/fraction-to-recurring-decimal/
# Author: Miao Zhang
# Date:   2021-01-24

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        n, remainder = divmod(abs(numerator), abs(denominator))
        sign = '-' if numerator * denominator < 0 else ''
        fraction = [sign + str(n)]
        if remainder == 0:
            return ''.join(fraction)
        
        fraction.append('.')
        dic = {}
        while remainder != 0:
            if remainder in dic:
                fraction.insert(dic[remainder], '(')
                fraction.append(')')
                break
            dic[remainder] = len(fraction)
            n, remainder = divmod(remainder * 10, abs(denominator))
            fraction.append(str(n))
        return ''.join(fraction)
