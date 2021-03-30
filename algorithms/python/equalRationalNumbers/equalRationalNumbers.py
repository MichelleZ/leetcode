#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/equal-rational-numbers/
# Author: Miao Zhang
# Date:   2021-03-29

class Solution:
    def isRationalEqual(self, s: str, t: str) -> bool:
        from fractions import Fraction
        def convert(x):
            if '.' not in x:
                return Fraction(int(x), 1)
            
            i = x.index('.')
            res = Fraction(int(x[:i]), 1)
            x = x[i + 1:]
            if '(' not in x:
                if x:
                    res += Fraction(int(x), 10 ** len(x))
                return res
            i = x.index('(')
            if i:
                res += Fraction(int(x[: i]), 10 ** i)
            x = x[i + 1: -1]
            j = len(x)
            res += Fraction(int(x), 10 ** i * (10 ** j - 1))
            return res
        
        return convert(s) == convert(t)
