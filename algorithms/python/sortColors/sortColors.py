#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/sort-colors/
# Author: Miao Zhang
# Date:   2021-01-14

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = 0;
        r = len(nums) - 1;
        i = 0
        while i <= r:
            if nums[i] == 2:
                nums[i], nums[r] = nums[r], nums[i]
                r -= 1;
            elif nums[i] == 0:
                nums[i], nums[l] = nums[l], nums[i]
                l += 1
                i += 1
            else:
                i += 1
