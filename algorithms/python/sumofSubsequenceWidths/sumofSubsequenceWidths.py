#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-subsequence-widths/
# Author: Miao Zhang
# Date:   2021-03-22

class Solution:
    def sumSubseqWidths(self, A: List[int]) -> int:
        kMod = 10 ** 9 + 7;
        n = len(A)
        A.sort()
        res = 0
        p = 1
        for i in range(n):
            res = (res + (A[i] - A[n - i - 1]) * p) % kMod
            p = (p << 1) % kMod
        return (res + kMod) % kMod
