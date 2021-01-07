#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/longest-valid-parentheses/
# Author: Miao Zhang
# Date:   2021-01-07

# if '(', push stack i
# if ')', pop and compute maxlen

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        start = 0
        maxlen = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if len(stack) == 0:
                    start = i + 1
                else:
                    stack.pop()
                    if len(stack) == 0:
                        maxlen = max(maxlen, i - start + 1)
                    else:
                        maxlen = max(maxlen, i - stack[-1])
        return maxlen
