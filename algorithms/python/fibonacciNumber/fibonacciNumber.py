#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/fibonacci-number/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def fib(self, n: int) -> int:
        if n == 0: return 0
        if n == 1: return 1
        return self.fib(n - 1) + self.fib(n - 2)
