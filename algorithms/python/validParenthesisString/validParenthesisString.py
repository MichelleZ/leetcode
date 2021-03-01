#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-parenthesis-string/
# Author: Miao Zhang
# Date:   2021-02-28

class Solution:
    def checkValidString(self, s: str) -> bool:
        low = 0
        high = 0
        for c in s:
            if c == '(':
                low += 1
            else:
                low -= 1
            if c != ')':
                high += 1
            else:
                high -= 1
            if high < 0: return False
            low = max(0, low)
        return low == 0
