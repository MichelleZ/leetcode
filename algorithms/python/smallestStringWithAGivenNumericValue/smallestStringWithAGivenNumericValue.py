#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
# Author: Miao Zhang
# Date:   2021-05-26

class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        res = ['a'] * n
        k -= n
        while k:
            d = min(k, 25)
            n -= 1
            res[n] = chr(ord('a') + d)
            k -= d
        return ''.join(res)
