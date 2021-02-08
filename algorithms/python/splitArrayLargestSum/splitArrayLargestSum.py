#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/split-array-largest-sum/
# Author: Miao Zhang
# Date:   2021-02-08

class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        l = max(nums)
        r = sum(nums) + 1
        while l < r:
            mid = l + (r - l) // 2
            if self.min_groups(nums, mid) > m:
                l = mid + 1
            else:
                r = mid
        return l
    
    def min_groups(self, nums: list[int], limit: int) -> int:
        k = 1
        sums = 0
        for n in nums:
            if sums + n > limit:
                sums = n
                k += 1
            else:
                sums += n
        return k
