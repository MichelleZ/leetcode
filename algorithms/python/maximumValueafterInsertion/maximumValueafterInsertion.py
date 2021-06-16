#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-value-after-insertion/
# Author: Miao Zhang
# Date:   2021-06-16

class Solution:
    def maxValue(self, n: str, x: int) -> str:
        l = len(n)
        if n[0] != '-':
            for i in range(l):
                if int(n[i]) < x:
                    return n[: i] + str(x) + n[i:]
            return n + str(x)
        else:
            for i in range(1, l):
                if int(n[i]) > x:
                    return n[: i] + str(x) + n[i:]
            return n + str(x)

