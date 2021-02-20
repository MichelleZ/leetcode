#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/single-element-in-a-sorted-array/
# Author: Miao Zhang
# Date:   2021-02-20

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = l + (r - l) // 2
            # n = m + 1 if m % 2 == 0 else m - 1
            n = mid ^ 1;
            if nums[mid] == nums[n]:
                l = mid + 1
            else:
                r = mid
        return nums[l]
