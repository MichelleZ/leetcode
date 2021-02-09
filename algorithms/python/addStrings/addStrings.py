#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/add-strings/
# Author: Miao Zhang
# Date:   2021-02-09

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ''
        carry, i, j = 0, len(num1) - 1, len(num2) - 1
        while i >= 0 or j >= 0 or carry > 0:
            if i >= 0:
                carry += ord(num1[i]) - ord('0')
            if j >= 0:
                carry += ord(num2[j]) - ord('0')
            res += str(carry % 10)
            carry //= 10
            i -= 1
            j -= 1
        return res[::-1]
