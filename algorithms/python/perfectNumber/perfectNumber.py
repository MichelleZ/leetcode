#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/perfect-number/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 1: return False
        res = 1
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                res += i + num / i
        return res == num
