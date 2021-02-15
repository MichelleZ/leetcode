#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/number-complement/
# Author: Miao Zhang
# Date:   2021-02-15

class Solution:
    def findComplement(self, num: int) -> int:
        mask = ~0
        while num & mask:
            mask <<= 1
        return ~num ^ mask
