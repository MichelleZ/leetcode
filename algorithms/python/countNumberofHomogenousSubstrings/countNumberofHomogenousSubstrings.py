#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-number-of-homogenous-substrings/
# Author: Miao Zhang
# Date:   2021-06-03

class Solution:
    def countHomogenous(self, s: str) -> int:
        kMod = 10 ** 9 + 7
        n = len(s)
        res = 0
        i = 0
        j = 0
        while i < n:
            while j < n and s[i] == s[j]:
                j += 1
            res += (j - i) * (j - i + 1) // 2
            i = j
        return res % kMod
