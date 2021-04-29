#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-happy-prefix/
# Author: Miao Zhang
# Date:   2021-04-29

class Solution:
    def longestPrefix(self, s: str) -> str:
        kMod = 16769023
        base = 128
        n = len(s)
        p = 0
        q = 0
        coe = 1
        res = 0
        for i in range(1, n):
            p = (p + coe * ord(s[i - 1])) % kMod
            q = (q * base + ord(s[n - i])) % kMod
            coe = (coe * base) % kMod
            if p == q and s[:i] == s[n - i:]:
                res = i
        return s[:res]
