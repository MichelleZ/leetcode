#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
# Author: Miao Zhang
# Date:   2021-04-26

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        arr.sort(key=lambda x: (bin(x).count('1'), x))
        return arr
