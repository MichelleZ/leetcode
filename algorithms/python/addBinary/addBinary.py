#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/add-binary/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        res = ''
        while i >= 0 or j >= 0:
            c = int(a[i]) if i >= 0 else 0
            d = int(b[j]) if j >= 0 else 0
            s = c + d + carry
            carry = s >> 1
            res += str(s & 1)
            i -= 1
            j -= 1
        if carry:
            res += '1'
        return res[::-1]
