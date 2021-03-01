#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/repeated-string-match/
# Author: Miao Zhang
# Date:   2021-03-01

class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        q = (len(b) - 1) // len(a) + 1
        for i in range(2):
            if b in a * (q+i): return q+i
        return -1
