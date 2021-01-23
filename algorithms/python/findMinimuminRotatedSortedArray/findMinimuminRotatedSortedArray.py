#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
# Author: Miao Zhang
# Date:   2021-01-22

class Solution:
    def findMin(self, nums: List[int]) -> int:
        return self.findmin(nums, 0, len(nums) - 1)
    
    
    def findmin(self, nums: List[int], l: int, r: int) -> int:
        if l + 1 >= r: 
            return min(nums[l], nums[r])
        if nums[l] < nums[r]: 
            return nums[l]
        mid = (l + r) // 2
        return min(self.findmin(nums, l, mid - 1), self.findmin(nums, mid, r))
        
