#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/maximum-erasure-value/
# Author: Miao Zhang
# Date:   2021-05-28

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        s = set()
        l = 0
        sums = 0
        res = 0
        for r in range(n):
            while nums[r] in s and l < r:
                s.remove(nums[l])
                sums -= nums[l]
                l += 1
            s.add(nums[r])
            sums += nums[r]
            res = max(res, sums)
        return res
