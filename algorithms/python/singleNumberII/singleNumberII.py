#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/single-number-ii/
# Author: Miao Zhang
# Date:   2021-01-21

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        # compute the numbers of every bit
        for i in range(32):
            count = 0
            for n in nums:
                count += (n >> i) & 1
            res |= (count % 3) << i
        return res - 2 ** 32 if res >> 31 & 1 else res
