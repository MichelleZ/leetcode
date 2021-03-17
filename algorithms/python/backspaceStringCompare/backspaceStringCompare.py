#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/backspace-string-compare/
# Author: Miao Zhang
# Date:   2021-03-17

class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        stack1 = []
        stack2 = []
        for s in S:
            if s == '#':
                if stack1:
                    stack1.pop()
            else:
                stack1.append(s)     
        for t in T:
            if t == '#':
                if stack2:
                    stack2.pop()
            else:
                stack2.append(t)
        return stack1 == stack2
