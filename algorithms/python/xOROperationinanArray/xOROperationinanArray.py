#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/xor-operation-in-an-array/
# Author: Miao Zhang
# Date:   2021-05-10

class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        s = start >> 1
        e = start & n & 1
        res = self.computexor(s - 1) ^ self.computexor(s + n - 1)
        return res << 1 | e

    def computexor(self, n: int):
        if n % 4 == 0:
            return n
        if n % 4 == 1:
            return 1
        if n % 4 == 2:
            return n + 1
        return 0
