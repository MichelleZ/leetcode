#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        idx = []
        i = 0
        while i < len(s1) and len(idx) <= 2:
            if s1[i] != s2[i]:
                idx.append(i)
            i += 1
        if len(idx) == 0: return True
        if len(idx) != 2: return False
        return s1[idx[0]] == s2[idx[1]] and s2[idx[0]] == s1[idx[1]]

