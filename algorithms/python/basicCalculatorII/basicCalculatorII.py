#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/basic-calculator-ii/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        num = 0
        pre_op = '+'
        for i, c in enumerate(s):
            if c.isdigit():
                num = 10 * num + int(c)
            if i == len(s) - 1 or c in '+-*/':
                if pre_op == '+':
                    stack.append(num)
                elif pre_op == '-':
                    stack.append(-num)
                elif pre_op == '*':
                    stack.append(stack.pop() * num)
                elif pre_op == '/':
                    top = stack.pop()
                    if top < 0:
                        stack.append((-top // num) * -1)
                    else:
                        stack.append(top // num)
                pre_op = c
                num = 0
        return sum(stack)
