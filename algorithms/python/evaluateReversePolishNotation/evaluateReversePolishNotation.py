#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/
# Author: Miao Zhang
# Date:   2021-01-22

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t in ['+', '-', '*', '/']:
                a = int(stack.pop())
                b = int(stack.pop())
                if t == '+':
                    stack.append(a + b)
                elif t == '-':
                    stack.append(b - a)
                elif t == '*':
                    stack.append(a * b)
                else:
                    stack.append(int(b / a))
            else:
                stack.append(t)
        
        return stack[0]
