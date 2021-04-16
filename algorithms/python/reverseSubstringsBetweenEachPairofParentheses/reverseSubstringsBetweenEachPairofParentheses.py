#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
# Author: Miao Zhang
# Date:   2021-04-16

class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        stack.append('')
        for c in s:
            if c == '(':
                stack.append('')
            elif c != ')':
                stack[-1] += c
            else:
                t = stack.pop()
                stack[-1] += t[::-1]
        return stack[-1]
