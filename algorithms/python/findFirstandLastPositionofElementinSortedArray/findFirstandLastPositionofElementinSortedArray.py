#! /usr/bin/env python3
# -*- coding: utf-8 -*-

# Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
# Author: Miao Zhang
# Date:   2021-01-07

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                start, end = mid, mid
                while start >= 0 and nums[start] == target:
                    start -= 1
                while end < len(nums) and nums[end] == target:
                    end += 1
                return [start + 1, end - 1]
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        return [-1, -1]
