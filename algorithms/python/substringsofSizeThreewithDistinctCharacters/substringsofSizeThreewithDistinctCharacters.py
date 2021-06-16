#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        res = 0
        n = len(s)
        if n < 3: return 0
        for i in range(n - 2):
            if s[i] != s[i + 1] and s[i + 1] != s[i + 2] and s[i] != s[i + 2]:
                res += 1
        return res
