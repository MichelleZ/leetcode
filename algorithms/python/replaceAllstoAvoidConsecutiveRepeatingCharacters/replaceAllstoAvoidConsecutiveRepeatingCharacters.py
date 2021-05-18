#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
# Author: Miao Zhang
# Date:   2021-05-18

class Solution:
    def modifyString(self, s: str) -> str:
        n = len(s)
        sl = list(s)
        for i in range(n):
            if sl[i] != '?':
                continue
            for c in 'abc':
                if (i == 0 or sl[i - 1] != c) and (i == n - 1 or sl[i + 1] != c):
                    sl[i] = c
                    break
        return ''.join(sl)
