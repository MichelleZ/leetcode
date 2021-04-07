#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/greatest-common-divisor-of-strings/
# Author: Miao Zhang
# Date:   2021-04-07

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) < len(str2): return self.gcdOfStrings(str2, str1)
        if not str2: return str1
        if str1[:len(str2)] != str2: return ''
        return self.gcdOfStrings(str1[len(str2):], str2)
