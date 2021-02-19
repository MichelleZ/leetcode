#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/base-7/
# Author: Miao Zhang
# Date:   2021-02-19

class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0: return '0'
        res = ''
        flag = num < 0
        num = abs(num)
        while num > 0:
            res += str(num % 7)
            num //= 7
        if flag: res += '-'
        return res[::-1]
