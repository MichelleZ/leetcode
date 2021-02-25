#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/solve-the-equation/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def solveEquation(self, equation: str) -> str:
        def parse(s: str) -> List[int]:
            a = 0
            b = 0
            num = 0
            sign = 1
            digit = False
            for c in s:
                if c.isdigit():
                    digit = True
                    num = num * 10 + int(c)
                else:
                    if c == 'x':
                        a += (num if digit else 1) * sign
                    else:
                        b += num * sign
                        sign = 1 if c == '+' else -1
                    digit = False
                    num = 0
            b += num * sign
            return [a, b]

        l, r = parse(equation.split('=')[0]), parse(equation.split('=')[1])
        l[0] -= r[0]
        r[1] -= l[1]
        if l[0] == 0:
            return "Infinite solutions" if r[1] == 0 else "No solution"
        return "x=" + str(r[1] // l[0])
