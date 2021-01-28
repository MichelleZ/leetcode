#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/power-of-two/
# Author: Miao Zhang
# Date:   2021-01-28

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n < 1: return False
        return not (n & (n - 1))
