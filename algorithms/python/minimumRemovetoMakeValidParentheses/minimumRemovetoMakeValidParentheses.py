#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
# Author: Miao Zhang
# Date:   2021-04-19

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        close = s.count(')')
        ope = 0
        res = ''
        for c in s:
            if c == '(':
                if ope == close:
                    continue
                ope += 1
            elif c == ')':
                close -= 1
                if ope == 0: continue
                ope -= 1
            res += c
        return res
