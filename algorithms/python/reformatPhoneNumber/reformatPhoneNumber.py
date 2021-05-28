#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reformat-phone-number/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace(' ', '').replace('-', '')
        res = [number[0]]
        for i in range(1, len(number)):
            if i % 3 == 0: res.append('-')
            res.append(number[i])
        if res[-2] == '-':
            res[-2], res[-3] = res[-3], res[-2]
        return ''.join(res)
