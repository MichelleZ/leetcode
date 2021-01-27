#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/basic-calculator/
# Author: Miao Zhang
# Date:   2021-01-27

class Solution:
    def calculate(self, s: str) -> int:
        res = 0
        num = 0
        sign = 1
        stack = []
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == "+" or c == "-":
                res += sign * num
                num = 0
                sign = 1 if c == "+" else -1
            elif c == "(":
                stack.append(res)
                stack.append(sign)
                res = 0
                sign = 1
            elif c == ")":
                res += sign * num
                num = 0
                res *= stack.pop()
                res += stack.pop()
        res += sign * num
        return res
