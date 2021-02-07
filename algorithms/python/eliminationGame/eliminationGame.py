#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/elimination-game/
# Author: Miao Zhang
# Date:   2021-02-07

class Solution:
    def lastRemaining(self, n: int) -> int:
        # interval between adjacent numbers
        step = 1
        # the first number in every line
        res = 1
        while step * 2 <= n: 
            res += step
            step *= 2
            if step * 2 > n: break
            if (n / step) % 2 == 1: res += step
            step *= 2
        return res
