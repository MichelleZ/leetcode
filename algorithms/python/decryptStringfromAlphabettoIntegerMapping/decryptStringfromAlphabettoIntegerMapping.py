#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
# Author: Miao Zhang
# Date:   2021-04-22

class Solution:
    def freqAlphabets(self, s: str) -> str:
        res = ''
        i = 0
        while i < len(s):
            if i + 2 < len(s) and s[i + 2] == '#':
                res += chr(int(s[i: i + 2]) - 1 + ord('a'))
                i += 2
            else:
                res += chr(int(s[i]) - 1 + ord('a'))
            i += 1
        return res
