#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/clumsy-factorial/
# Author: Miao Zhang
# Date:   2021-04-01

class Solution:
    def clumsy(self, N: int) -> int:
        if N <= 0: return 0
        if N == 1: return 1
        if N == 2: return 2 * 1
        if N == 3: return 3 * 2 // 1
        
        res = N * (N - 1) // (N - 2) + (N - 3)
        N -= 4
        while N >= 4:
            res = res - N * (N - 1) // (N - 2) + (N - 3)
            N -= 4
        
        return res - self.clumsy(N)
