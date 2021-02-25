#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-square-numbers/
# Author: Miao Zhang
# Date:   2021-02-25

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = int(c ** 0.5)
        while a <= b:
            if a * a + b * b == c: return True
            elif a * a + b * b < c: a += 1
            else: b -= 1
        return False
