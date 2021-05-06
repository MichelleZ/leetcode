#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
# Author: Miao Zhang
# Date:   2021-05-05

class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        if k == 0: return 0
        f1 = 1
        f2 = 1
        while f2 <= k:
            f1, f2 = f2, f1
            f2 += f1
        return 1 + self.findMinFibonacciNumbers(k - f1)
