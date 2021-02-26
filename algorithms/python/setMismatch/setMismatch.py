#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/set-mismatch/
# Author: Miao Zhang
# Date:   2021-02-26

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        dup = -1
        missing = -1
        for n in nums:
            if nums[abs(n) - 1] < 0:
                dup = abs(n)
            else:
                nums[abs(n) - 1] *= -1
        for i in range(len(nums)):
            if nums[i] > 0:
                missing = i + 1
        return [dup, missing]
