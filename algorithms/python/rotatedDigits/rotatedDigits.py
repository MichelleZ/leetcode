#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/rotated-digits/
# Author: Miao Zhang
# Date:   2021-03-10

class Solution:
    def rotatedDigits(self, N: int) -> int:
        res = 0
        for i in range(1, N + 1):
            res += self.isValid(i)
        return res
    
    def isValid(self, n: int) -> int:
        s = str(n)
        t = list(s)
        for i in range(len(s)):
            if s[i] == '3' or s[i] == '4' or s[i] == '7':
                return 0
            elif s[i] == '2':
                t[i] = '5'
            elif s[i] == '5':
                t[i] = '2'
            elif s[i] == '6':
                t[i] = '9'
            elif s[i] == '9':
                t[i] = '6'
        return ''.join(t) != s
