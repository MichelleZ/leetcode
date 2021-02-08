#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
# Author: Miao Zhang
# Date:   2021-02-08

class Solution:
    def toHex(self, num: int) -> str:
        dic = "0123456789abcdef";
        if num == 0: return '0'
        if num < 0: num += 2 ** 32
        res = ''
        while num:
            res = dic[num % 16] + res
            num //= 16
        return res
        
