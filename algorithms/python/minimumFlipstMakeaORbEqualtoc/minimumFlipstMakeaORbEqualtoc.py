#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
# Author: Miao Zhang
# Date:   2021-04-23

class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        res = 0
        while a or b or c:
            if ((a & 1) or (b & 1)) != c & 1:
                res += 1 + (a & 1) * (b & 1)
            a >>= 1
            b >>= 1
            c >>= 1
        return res
