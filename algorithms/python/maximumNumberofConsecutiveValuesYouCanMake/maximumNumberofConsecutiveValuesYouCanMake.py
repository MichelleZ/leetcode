#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
# Author: Miao Zhang
# Date:   2021-06-08

class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        coins.sort()
        x = 0
        for c in coins:
            if c > x + 1: break
            x += c
        return x + 1
