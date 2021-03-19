#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/binary-gap/
# Author: Miao Zhang
# Date:   2021-03-19

class Solution:
    def binaryGap(self, n: int) -> int:
        res = 0
        last_one = None
        for i, n in enumerate(bin(n)[2:]):
            if n == '1':
                if last_one is not None:
                    res = max(res, i - last_one)
                last_one = i
        return res
