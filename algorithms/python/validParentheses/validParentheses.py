#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-parentheses/
# Author: Miao Zhang
# Date:   2021-01-06

class Solution:
    def isValid(self, s: str) -> bool:
        dicts = {')': '(', '}': '{', ']': '['}
        stack = []
        for c in s:
            if c in dicts.values():
                stack.append(c)
            elif c in dicts.keys():
                if stack == [] or stack.pop() != dicts[c]:
                    return False
            else:
                return False
        return stack == []
