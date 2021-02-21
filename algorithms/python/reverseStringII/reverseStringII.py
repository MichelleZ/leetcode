#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-string-ii/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        n = len(s)
        res = ""
        for i in range(0, n, 2 * k):
            tmp = s[i: i + k]
            res = res + tmp[::-1] + s[i + k: i + 2 * k]
        return res
