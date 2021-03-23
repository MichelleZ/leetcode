#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-array-by-parity/
# Author: Miao Zhang
# Date:   2021-03-23

class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        A.sort(key=lambda x: x % 2)
        return A
