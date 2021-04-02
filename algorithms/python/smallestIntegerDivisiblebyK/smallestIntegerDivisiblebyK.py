#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/smallest-integer-divisible-by-k/
# Author: Miao Zhang
# Date:   2021-04-02

class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0:
            return -1
        r = 0
        for i in range(1, K + 1):
            r = (r * 10 + 1) % K
            if r == 0: 
                return i
        return -1
