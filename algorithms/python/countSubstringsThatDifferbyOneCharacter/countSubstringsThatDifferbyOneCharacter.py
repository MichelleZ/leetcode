#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
# Author: Miao Zhang
# Date:   2021-05-24

class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        m = len(s)
        n = len(t)
        res = 0
        for i in range(m):
            for j in range(n):
                diff = 0
                p = 0
                while i + p < m and j + p < n and diff <= 1:
                    diff += (s[i + p] != t[j + p])
                    if diff == 1:
                        res += 1
                    p += 1
        return res
