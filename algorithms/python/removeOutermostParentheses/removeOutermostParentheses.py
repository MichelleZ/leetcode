#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/remove-outermost-parentheses/
# Author: Miao Zhang
# Date:   2021-04-03

class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        res = ''
        n = 0
        for c in S:
            if c == '(':
                if n:
                    res += c
                n += 1
            if c == ')':
                n -= 1
                if n:
                    res += c
        return res

