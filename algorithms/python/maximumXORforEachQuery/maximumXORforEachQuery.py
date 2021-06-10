#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-xor-for-each-query/
# Author: Miao Zhang
# Date:   2021-06-10

class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        maxval = (1 << maximumBit) - 1
        n = len(nums)
        res = [0 for _ in range(n)]
        sums = 0
        for num in nums: sums ^= num
        for i in range(n - 1, -1, -1):
            res[n - 1 - i] = sums ^ maxval
            sums ^= nums[i]
        return res
