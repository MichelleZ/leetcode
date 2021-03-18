#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/score-of-parentheses/
# Author: Miao Zhang
# Date:   2021-03-18

class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        res = 0
        d = -1
        for i in range(len(S)):
            d += 1 if S[i] == '(' else -1
            if S[i] == '(' and S[i + 1] == ')':
                res += 1 << d
        return res
