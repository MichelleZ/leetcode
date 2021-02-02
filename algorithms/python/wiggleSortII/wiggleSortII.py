#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/wiggle-sort-ii/
# Author: Miao Zhang
# Date:   2021-02-02

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        mid = (len(nums) + 1) // 2
        left, right = nums[:mid], nums[mid:]
        nums[::2] = left[::-1]
        nums[1::2] = right[::-1]
