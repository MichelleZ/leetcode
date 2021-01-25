#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reverse-bits/
# Author: Miao Zhang
# Date:   2021-01-25

class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            res <<= 1
            res |= n & 1
            n >>= 1
        return res
