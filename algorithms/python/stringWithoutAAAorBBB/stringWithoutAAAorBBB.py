#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/string-without-aaa-or-bbb/
# Author: Miao Zhang
# Date:   2021-03-30

class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        s1 = 'a'
        s2 = 'b'
        if b > a:
            s1, s2 = s2, s1
            a, b = b, a
        res = ''
        while a or b:
            if a > 0: 
                res += s1
                a -= 1
            if a > b: 
                res += s1
                a -= 1
            if b > 0:
                res += s2
                b -= 1
        return res
