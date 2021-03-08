#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reach-a-number/
# Author: Miao Zhang
# Date:   2021-03-07

class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        sumval = 0
        k = 0
        while sumval < target:
            k += 1
            sumval += k
        d = sumval - target
        if d % 2 == 0: return k
        return k + 1 + (k % 2)
