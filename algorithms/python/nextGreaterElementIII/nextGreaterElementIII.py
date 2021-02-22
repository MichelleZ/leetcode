#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/next-greater-element-iii/
# Author: Miao Zhang
# Date:   2021-02-22

class Solution:
    def nextGreaterElement(self, n: int) -> int:
        s = list(str(n))
        i = len(s) - 1
        while i > 0:
            if s[i] > s[i - 1]: break
            i -= 1
        if i == 0: return -1
        for j in range(len(s) - 1, i - 1, -1):
            if s[j] > s[i - 1]:
                s[j], s[i - 1] = s[i - 1], s[j]
                break
        s[i:] = s[i:][::-1]
        res = int(''.join(s))
        if res <= 2 ** 31 - 1:
            return res
        return -1
