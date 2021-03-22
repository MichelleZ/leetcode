#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/fair-candy-swap/
# Author: Miao Zhang
# Date:   2021-03-22

class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        suma = sum(A)
        sumb = sum(B)
        diff = (sumb - suma) // 2
        b = set(B)
        for a in A:
            if a + diff in B:
                return [a, a + diff]
