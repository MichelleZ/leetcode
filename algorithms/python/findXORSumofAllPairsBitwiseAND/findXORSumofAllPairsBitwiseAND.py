#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        return reduce(xor, arr1, 0) & reduce(xor, arr2, 0)
