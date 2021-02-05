#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/wiggle-subsequence/
# Author: Miao Zhang
# Date:   2021-02-05

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1: return n
        inc, dec = 1, 1
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                inc = dec + 1
            elif nums[i] < nums[i - 1]:
                dec = inc + 1
        return max(inc, dec)
