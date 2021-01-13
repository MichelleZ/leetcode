#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/plus-one/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits) - 1
        while n >= 0:
            if digits[n] < 9:
                digits[n] += 1
                return digits
            digits[n] = 0
            n -= 1
        res = [0 for _ in range(len(digits) + 1)]
        res[0] = 1
        return res
