#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/next-permutation/
# Author: Miao Zhang
# Date:   2021-01-07

# Find the last num in ascending order from the end
# 2, 3, 1,  i = pos of 3, j = pos of 2
# Find the first num that is greater than j
# swap 2 and 3, 
# 3, 2, 1
# the part after j sort

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 1
        while i > 0:
            if nums[i - 1] >= nums[i]:
                i -= 1
            else:
                break
        if i == 0:
            return nums.sort()
        j = i - 1
        for i in range(len(nums) - 1, j, -1):
            if nums[i] > nums[j]:
                break
        nums[j], nums[i] = nums[i], nums[j]
        nums[j + 1:] = sorted(nums[j + 1:])
        return nums
