#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/happy-number/
# Author: Miao Zhang
# Date:   2021-01-25

class Solution:
    def isHappy(self, n: int) -> bool:
        middle = set()
        while n not in middle:
            middle.add(n)
            n = sum(int(i) ** 2 for i in str(n))
        return n == 1
