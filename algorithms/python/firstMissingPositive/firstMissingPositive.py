#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/first-missing-positive/
# Author: Miao Zhang
# Date:   2021-01-08

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[nums[i] - 1] != nums[i]:
                nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1;
        return len(nums) + 1

