#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/multiply-strings/
# Author: Miao Zhang
# Date:   2021-01-09

# n = 1 min is 10 ^ (1 - 1), max is 10 ^ 1 - 1
# n = 2 min is 10 ^ (2 - 1), max is 10 ^ 2 - 1
# len(num1) = n1, len(num2) = n2, len(result) = n1 + n2 or n1 + n2 - 1
#      1 2
# x    3 4
# --------
#      0 8
#    0 4
#    0 6
#  0 3
#---------
#  0 4 0 8
# i0 1 2 3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'
        
        n1, n2 = len(num1), len(num2)
        res = [0] * (n1 + n2)
        for i in range(n1 - 1, -1, -1):
            a = int(num1[i])
            for j in range(n2 - 1, -1, -1):
                b = int(num2[j])
                c = res[i + j + 1] + a * b
                res[i + j] += c // 10
                res[i + j + 1] = c % 10
        res = res[1:] if res[0] == 0 else res
        return ''.join(str(i) for i in res)
