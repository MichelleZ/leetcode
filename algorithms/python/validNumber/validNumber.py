#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/valid-number/
# Author: Miao Zhang
# Date:   2021-01-13

class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        is_digit, is_dot, is_e = False, False, False
        
        for i in range(len(s)):
            if s[i].isdecimal():
                is_digit = True
            elif s[i] in '+-':
                if i != 0 and s[i - 1] != 'e':
                    return False
            elif s[i] == '.':
                if is_dot or is_e:
                    return False
                is_dot = True
            elif s[i].lower() == 'e':
                if not is_digit or is_e:
                    return False
                is_digit = False
                is_e = True
            else:
                return False
        return is_digit
