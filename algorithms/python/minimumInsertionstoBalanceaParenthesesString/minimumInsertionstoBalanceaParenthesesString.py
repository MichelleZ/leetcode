#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
# Author: Miao Zhang
# Date:   2021-05-14

class Solution:
    def minInsertions(self, s: str) -> int:
        res = 0
        close = 0
        for c in s:
            if c == ')':
                close -= 1
                if close < 0:
                    res += 1
                    close += 2
            else:
                if close & 1:
                    res += 1
                    close -= 1
                close += 2
        return res + close
