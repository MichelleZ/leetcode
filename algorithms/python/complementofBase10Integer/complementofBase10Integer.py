#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/complement-of-base-10-integer/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def bitwiseComplement(self, N: int) -> int:
        num = 1
        while num < N:
            num = (num << 1) + 1
        return num ^ N
