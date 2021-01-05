#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/roman-to-integer/
# Author: Miao Zhang
# Date:   2021-01-05

class Solution:
    def romanToInt(self, s: str) -> int:
        s2v = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res = 0
        for i in range(len(s)):
            val = s2v[s[i]]
            if i == len(s) - 1 or s2v[s[i + 1]] <= val:
                res += val
            else:
                res -= val
        return res
