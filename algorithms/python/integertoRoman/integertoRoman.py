#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/integer-to-roman/
# Author: Miao Zhang
# Date:   2021-01-05

class Solution:
    def intToRoman(self, num: int) -> str:
        dicts = {
            1:    'I',
            4:    'IV',
            5:    'V',
            9:    'IX',
            10:   'X',
            40:   'XL',
            50:   'L',
            90:   'XC',
            100:  'C',
            400:  'CD',
            500:  'D',
            900:  'CM',
            1000: 'M'
        }
        
        res = ''
        for key in sorted(dicts.keys())[::-1]:
            tmp = num // key
            if tmp == 0:
                continue
            res += tmp * dicts[key]
            num -= tmp * key
            if num == 0:
                break
        return res
