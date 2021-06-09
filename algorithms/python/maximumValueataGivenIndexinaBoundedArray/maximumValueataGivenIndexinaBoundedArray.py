#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        l, r = 1, maxSum + 1
        while l < r:
            m = l + (r - l) // 2
            t1 = m - index
            t2 = m - (n - 1 - index)
            s1 = (t1 + m) * (index + 1) // 2
            s2 = (m + t2) * (n - index) // 2
            if t1 <= 0: s1 = (1 + m) * m / 2 + (index - m + 1)
            if t2 <= 0: s2 = (1 + m) * m / 2 + (n - index - m)
            if s1 + s2 - m > maxSum:
                r = m
            else:
                l = m + 1
        return l - 1
