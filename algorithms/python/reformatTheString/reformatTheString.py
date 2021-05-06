#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reformat-the-string/
# Author: Miao Zhang
# Date:   2021-05-06

class Solution:
    def reformat(self, s: str) -> str:
        s1 = []
        s2 = []
        for c in s:
            if c.isalpha():
                s1.append(c)
            else:
                s2.append(c)
        if len(s1) < len(s2):
            s1, s2 = s2, s1
        if abs(len(s1) - len(s2)) > 1:
            return ''
        res = ''
        n = len(s1) + len(s2)
        for i in range(n):
            if i % 2 == 0:
                res += s1[i // 2]
            else:
                res += s2[i // 2]
        return res
