#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/reordered-power-of-2/
# Author: Miao Zhang
# Date:   2021-03-19

class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        counter = collections.Counter(str(N))
        for i in range(31):
            if counter == collections.Counter(str(1 << i)):
                return True
        return False
