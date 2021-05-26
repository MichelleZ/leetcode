#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/ways-to-make-a-fair-array/
# Author: Miao Zhang
# Date:   2021-05-26

class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        n = len(nums)
        prefixsum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefixsum[i] = prefixsum[i - 1] + (nums[i - 1] if i % 2 else -nums[i - 1])
        res = 0
        for i in range(1, n + 1):
            if prefixsum[i - 1] == prefixsum[n] - prefixsum[i]:
                res += 1
        return res
