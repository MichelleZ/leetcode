#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
# Author: Miao Zhang
# Date:   2021-06-15

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for i in range(1 << n):
            tmp = 0
            for j in range(n):
                if i & (1 << j):
                    tmp ^= nums[j]
            res += tmp
        return res
