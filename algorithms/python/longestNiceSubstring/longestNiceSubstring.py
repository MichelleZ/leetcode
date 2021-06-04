#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-nice-substring/
# Author: Miao Zhang
# Date:   2021-06-04

class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        res = ''
        for i in range(n):
            u = [0] * 26
            l = [0] * 26
            for j in range(i, n):
                c = s[j]
                if c.isupper(): u[ord(c) - ord('A')] = 1
                else: l[ord(c) - ord('a')] = 1
                if u == l and j - i + 1 > len(res):
                    res = s[i: j + 1]
        return res
