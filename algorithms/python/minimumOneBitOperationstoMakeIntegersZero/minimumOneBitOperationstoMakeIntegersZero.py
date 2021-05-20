#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
# Author: Miao Zhang
# Date:   2021-05-20

class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        res = 0
        while n:
            res ^= n
            n >>= 1
        return res
