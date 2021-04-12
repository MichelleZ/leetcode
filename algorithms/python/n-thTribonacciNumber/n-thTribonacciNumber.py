#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/n-th-tribonacci-number/
# Author: Miao Zhang
# Date:   2021-04-12

class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return 1 if n else 0

        a, b, c = 0, 1, 1
        for _ in range(n - 2):
            a, b, c = b, c, a + b + c
        return c

