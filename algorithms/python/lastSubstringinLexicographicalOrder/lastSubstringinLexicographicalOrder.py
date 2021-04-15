#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/last-substring-in-lexicographical-order/
# Author: Miao Zhang
# Date:   2021-04-15

class Solution:
    def lastSubstring(self, s: str) -> str:
        maxc = 'a'
        for c in s:
            if c > maxc: 
                maxc = c
        if maxc == 'a':
            return s
        res = ''
        for i in range(len(s)):
            if s[i] == maxc:
                if res == '':
                    res = s[i:]
                else:
                    res = max(res, s[i:])
        return res
