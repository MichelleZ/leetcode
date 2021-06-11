#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/replace-all-digits-with-characters/
# Author: Miao Zhang
# Date:   2021-06-11

class Solution:
    def replaceDigits(self, s: str) -> str:
        res = list(s)
        for i in range(1, len(s), 2):
            res[i] = chr(ord(res[i - 1]) + int(res[i]))
        return ''.join(res)
