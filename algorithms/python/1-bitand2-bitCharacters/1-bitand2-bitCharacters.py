#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/1-bit-and-2-bit-characters/
# Author: Miao Zhang
# Date:   2021-03-03

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)
        i = 0
        while i < n - 1:
            i += bits[i] + 1
        return i == n - 1
