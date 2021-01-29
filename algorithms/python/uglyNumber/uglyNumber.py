#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ugly-number/
# Author: Miao Zhang
# Date:   2021-01-29

class Solution:
    def isUgly(self, num: int) -> bool:
        factors = [2, 3, 5]
        for fac in factors:
            while num and num % fac == 0:
                num /=  fac
        return num == 1
